# 🦀 Installing Rust & Cargo

A 2-minute guide to get the full Rust toolchain on **macOS**, **Linux** or **Windows**  

---

## 1️⃣ One-liner install (Unix)

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

 🔍 Want to read the script first?  
 `curl -sSf https://sh.rustup.rs  rustup.sh && less rustup.sh`

After the installer finishes **restart your shell** (or `source "$HOME/.cargo/env"`).

---

## 2️⃣ Windows installer

Download and run [`rustup-init.exe`](https://rustup.rs) – it opens a console and walks you through the steps.

---

## 3️⃣ Verify everything

```bash
rustc --version   # e.g. rustc 1.82.0 (f6e511eec 2025-10-15)
cargo  --version   # e.g. cargo 1.82.0 (8f40fc59f 2025-10-08)
```

 ✅ If both commands print a version → you’re golden.

---

## 4️⃣ Keep it fresh 🌿

```bash
rustup update      # update toolchain
rustup self uninstall  # remove everything cleanly
```

---

## 5️⃣ Quick sanity check project

```bash
cargo new hello_ferris
cd hello_ferris
cargo run          # Hello, world!
```

---

## 🔗 Official links

| What                 | URL |
|----------------------|-----|
| Install page         | https://rust-lang.org/tools/install |
| Cargo Book           | https://doc.rust-lang.org/cargo |
| Release notes        | https://github.com/rust-lang/rust/releases |
| Community chat       | https://rust-lang.zulipchat.com |

---

## 🧩 Obsidian extras

* **Run code blocks**: install the “Shell commands” plugin and bind `cargo run` to a hot-key.  
* **Update this note**: paste the command below in a code block and execute it from Obsidian when you want the latest stable toolchain.

```bash
rustup update stable
```

---

## 📦 Bonus tools (install via cargo)

| Tool           | Purpose                          | Install line |
|----------------|----------------------------------|--------------|
| `cargo-edit`   | Add/remove deps from CLI         | `cargo install cargo-edit` |
| `cargo-watch`  | Re-run on file change            | `cargo install cargo-watch` |
| `cargo-generate` | Scaffold from templates        | `cargo install cargo-generate` |

---
