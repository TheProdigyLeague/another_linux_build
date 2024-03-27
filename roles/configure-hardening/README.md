![ansible](https://github.com/TheProdigyLeague/another_linux_build/assets/30985576/80af0d6f-5bc8-4903-879b-afffe42b0c95)

# Config Hardening

The configuration of several security-hardening mechanisms on a target system is the main goal of this Ansible(c) playbook. The playbook is modular, with distinct tasks for various facets of system hardening arranged inside it.


## Included Tasks

1. **srvc.config**
   - `services.yml`
   - `task/config/man/sys.srvc`

2. **Kernel para hardening**
   - `kernel_param.yml`
   - `task/config/kernel-para/` for enhancing security.

3. **Banner Configuration**
   - `banner.yml`
   - sys config banner

4. **firewall config**
   - `ufw.yml`
   - firewall rules

5. **BIOS**
   - `bios.yml`
   - Run `dmidecode` tasks to retrieve BIOS information and displaying the BIOS version.

6. **i3 Windows Manager Configuration**
   - `i3.yml
    
7. **Additional Hardening Measures**
   - `ntp.yml`
# eof
