![ansible](https://github.com/TheProdigyLeague/another_linux_build/assets/30985576/ac0147e2-cb1e-4a05-8e32-22995b6681ec)

# Updating Firefox Policies

Using the Mozilla(c) policy templates, this Ansible(c) job will automate the process of upgrading Firefox rules on a target machine. The `policies.json` file is customized by the task using the Jinja2 template engine, and it is then deployed to the designated location on the target system.

## Task Details

- **Task Name:** Updating Firefox Policies
- **Task Module:** `template`
- **Source Template:** `templates/policies.json.j2`
- **Destination Path:** `/usr/share/firefox-esr/distribution/policies.json`
- **Privilege Escalation:** The task uses `become` with `sudo` as the privilege escalation method.

# eof
