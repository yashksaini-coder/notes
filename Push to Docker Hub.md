---
tags:
  - devops
  - docker
---
---
Publishing a Docker container to Docker Hub involves the following steps:

---

### ✅ 1. **Create a Docker Hub Account**

Go to [https://hub.docker.com/](https://hub.docker.com/) and sign up for an account if you don't already have one.

---

### ✅ 2. **Login to Docker Hub (CLI)**

Make sure Docker is installed on your system.

```bash
docker login
```

It will prompt for your **Docker Hub username** and **password** (or token if you use 2FA).

---

### ✅ 3. **Build Your Docker Image**

Navigate to your project directory where your `Dockerfile` is located and run:

```bash
docker build -t yourdockerhubusername/image-name:tag .
```

Example:

```bash
docker build -t yashsaini/myapp:latest .
```

---

### ✅ 4. **Tag the Docker Image (optional if already done)**

If you didn't tag it during build, you can tag it later:

```bash
docker tag local-image-id yourdockerhubusername/image-name:tag
```

You can get the local image ID with:

```bash
docker images
```

---

### ✅ 5. **Push the Image to Docker Hub**

```bash
docker push yourdockerhubusername/image-name:tag
```

Example:

```bash
docker push yashsaini/myapp:latest
```

---

### ✅ 6. **Verify on Docker Hub**

Go to your [Docker Hub repository dashboard](https://hub.docker.com/repositories) to confirm the image has been pushed.

---

### 🧹 Optional: Clean Up

```bash
docker image rm yashsaini/myapp:latest
```

---

### 📌 Example Full Workflow

```bash
# Navigate to project
cd myproject

# Login
docker login

# Build
docker build -t yashsaini/myapp:latest .

# Push
docker push yashsaini/myapp:latest
```

Let me know if you're using a `docker-compose.yml`, GitHub Actions, or want to automate this in CI/CD — I can guide you through that as well.