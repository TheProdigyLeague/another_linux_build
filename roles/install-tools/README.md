![ansible](https://github.com/TheProdigyLeague/another_linux_build/assets/30985576/cdf38f92-d373-4d91-b1be-13d2b580c820)

# Ansible(c) Playbook

## Tools

Ansible(c) focuses on installing various tools and utilities on a target, system, modular, and with separate tasks for different categories of tools.

### Included Tasks

1. **apt pkg install**
   - `apt.yml`
   - Essential packages based on selected installation mode (`light` or `full`).

2. **Burp Suite**
   - `burp.yml`
   - Downloads and configures Burp Suite Community and Pro versions, including CA certificate setup.

3. **Ruby Gems**
   - File: `gem.yml`
   - Installs Ruby gems used for various purposes.

4. **GitHub Repositories Cloning**
   - `github.yml`
   - Clones various GitHub repositories into `/opt/` directory.

5. **Pip Packages**
   - `pip.yml`
   - Installs Python packages using pip or pipx, including some tools and libraries.

~~6. **Sublime Text**- `sublimetext.yml` Installs Sublime Text and configures user preferences.~~

7. **ZedEncrypt Installation**
   - `zedencrypt.yml`
   - Installs ZedEncrypt tool on target system.
-- eof --
