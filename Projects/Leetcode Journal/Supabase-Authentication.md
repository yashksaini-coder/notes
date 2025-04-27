---
tags:
  - project
  - auth
date: 3-3-25
---
---
## Problem Solved

I implemented a complete authentication flow using `Supabase` in my Next.js application with the following features:

- Protected routes with server-side middleware
- Client-side authentication state management with `Zustand`
- Login and registration functionality
- Proper redirects based on authentication status
## Solution Approach

### 1. Middleware for Route Protection

I created a middleware that:
- Intercepts all requests
- Checks authentication status using Supabase's server client
- Redirects unauthenticated users away from protected routes
- Prevents authenticated users from accessing login/signup pages
- Handles cookies properly for the Supabase client
### 2. Client-Side Auth Store

I implemented a Zustand store that:
- Manages authentication state
- Handles login and signup processes
- Fetches user data
- Manages loading states and error messages
- Uses proper error handling
### 3. Key Improvements

- Used `window.location.href` instead of Next.js router for more reliable redirects after authentication changes
- Added proper error handling with specific error messages
- Implemented loading states to improve UX during authentication operations
## Code Structure  

The implementation is split between:

- `/utils/supabase/middleware.ts` - Server-side authentication checks

```typescript
import { createServerClient } from '@supabase/ssr'
import { NextResponse, type NextRequest } from 'next/server'

export async function updateSession(request: NextRequest) {
  let supabaseResponse = NextResponse.next({
    request,
  })
  const supabase = createServerClient(
    process.env.NEXT_PUBLIC_SUPABASE_URL!,
    process.env.NEXT_PUBLIC_SUPABASE_ANON_KEY!,
    {
      cookies: {
        getAll() {
          return request.cookies.getAll()
        },
        setAll(cookiesToSet) {
          cookiesToSet.forEach(({ name, value, options }) => request.cookies.set(name, value))
          supabaseResponse = NextResponse.next({
            request,
          })
          cookiesToSet.forEach(({ name, value, options }) =>
            supabaseResponse.cookies.set(name, value, options)
          )
        },
      },
    }
  )

  // IMPORTANT: DO NOT REMOVE auth.getUser()
  const {
    data: { user },
  } = await supabase.auth.getUser()

  // Protected routes check - redirect to signin if not authenticated
  if (
    !user && (request.nextUrl.pathname.startsWith('/dashboard'))
  ) {
    const url = request.nextUrl.clone()
    url.pathname = '/auth/signin'
    return NextResponse.redirect(url)
  }

  // Redirect authenticated users away from auth pages
  if (
    user &&
    (request.nextUrl.pathname === '/' ||
      request.nextUrl.pathname.startsWith('/auth/signin') ||
      request.nextUrl.pathname.startsWith('/auth/signup'))
  ) {
    // Add a cache-busting parameter to avoid redirect loops
    const url = request.nextUrl.clone()
    url.pathname = '/dashboard'
    url.searchParams.set('_ts', Date.now().toString())
    return NextResponse.redirect(url)
  }
  
  return supabaseResponse
}
```

- `/store/AuthStore/useAuthStore.ts` - Client-side state management
```typescript
import { createClient } from '@/utils/supabase/client'
import axios from 'axios';
import { create } from 'zustand'

interface User {
    id?: string;
    email: string;
    password: string;
    gender: string;
    fullName: string;
    leetcodeUsername: string;
}

interface authStore {
    isSigningIn: boolean;
    signinError: string | null;
    signin: (signinMetaData: { email: string, password: string },router: any) => void;
    logout: (router: any) => void;
    signupError: string | null;
    isSigningUp: boolean;
    signup: (signupMetaData: User,router: any) => void;
    user: User | null;
    authUserLoading: boolean;
    fetchAuthUser: () => void;
    authUser: User | null;
}
  
export const useAuthStore = create<authStore>((set) => ({
    signinError: null,
    isSigningIn: false,
    signin: async (signinMetaData, router) => {
        const supabase = createClient()
        set({ isSigningIn: true, signinError: null })
        try {
            const { data, error: loginError } =
                await supabase.auth.signInWithPassword(signinMetaData);
  
            if (loginError) {
                set({ signinError: loginError.message })
                console.log(loginError.message);
                return
            }
  
            if (data.session) {
                // For reliable redirection, reload the page instead of using router.push

               // This ensures the middleware properly detects the authentication state

                window.location.href = '/dashboard';
            } else {
                throw new Error("Unable to retrieve session after login.");
            }
        } catch (err: any) {
            console.error("Login Error:", err);
            set({ signinError: err.message || "Something went wrong. Please try again." });
        } finally {
            set({ isSigningIn: false })
        }
    },
    logout: async (router) => {
        const supabase = createClient()
        try {
            await supabase.auth.signOut();
            // Use window.location for reliable redirection after logout
            window.location.href = '/auth/signin';
        } catch (error) {
            console.error('Logout error:', error);
        }
    },
  
    signupError: null,
    isSigningUp: false,
    signup: async (signupMetaData,router) => {
  
        set({ isSigningUp: true });
        try {
            const response = await axios.post('/api/auth/register', signupMetaData);
            if (response.status === 201) {
                set({ user: signupMetaData });
                router.push('/auth/signin');
                set({ signupError: null });
            }
        } catch (error: any) {
            let err = error.response.data;
            console.error('Error:', err.message);
            set({ signupError: err.message || 'Something went wrong. Please try again.' });
        } finally {
            set({ isSigningUp: false });
        }
    },
    user: null,
  
    authUserLoading: true,
    authUser: null,
    fetchAuthUser: async () => {
        try {
            set({ authUserLoading: true });
            const response = await axios.get('/api/auth/user');
            if (response.status === 200) {
                set({ authUser: response.data.user });
            }
        } catch (err: any) {
            console.error('Error fetching user data:', err);
        } finally {
            set({ authUserLoading: false });
        }
    },
}));
```

---

 # Next Steps
- [ ] ~~Add password reset functionality
- [ ] ~~Implement email verification
- [ ] ~~Add social login options

---
