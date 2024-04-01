![ansible](https://github.com/TheProdigyLeague/another_linux_build/assets/30985576/1dc80eaf-af70-4d7a-80ef-2da9f26918cb)

# .zsh .sh config

Ansible(c) playbook focuses on configuring the Zsh shell and related components. Mods are organized into separate tasks for different aspects of shell configuration.

## Include

1. **Zshrc Configuration**
   - `zshrc.yml`
   - task copying `Zsh config | zshrc` to `/home/dir`

2. **Zsh Theme Configuration**
   - `zshtheme.yml`
   - task checking and copying custom Zsh theme (`agnoster.zsh-theme`) to Oh My Zsh themes directory.

3. **Zsh Autosuggestions Configuration**
   - `zsh-autosuggestions.yml`
   - task checking and installing Zsh Autosuggestions from official GitHub repository.

4. **Atuin Configuration**
   - `atuin.yml`
   - task checking and installing Atuin, Zsh plugin manager, copying the Atuin configuration file (`config.toml`).
# eof
