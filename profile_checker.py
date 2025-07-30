import subprocess

def get_git_config(key):
    try:
        result = subprocess.check_output(["git", "config", "--global", key])
        return result.decode("utf-8").strip()
    except subprocess.CalledProcessError:
        return "Not set"

def main():
    name = get_git_config("user.name")
    email = get_git_config("user.email")

    print("🔍 Current Git Global Profile:")
    print(f"👤 Username: {name}")
    print(f"📧 Email:    {email}")

if __name__ == "__main__":
    main()
# import subprocess

def get_git_config(key):
    try:
        result = subprocess.check_output(["git", "config", "--global", key])
        return result.decode("utf-8").strip()
    except subprocess.CalledProcessError:
        return "Not set"

def main():
    name = get_git_config("user.name")
    email = get_git_config("user.email")

    print("🔍 Current Git Global Profile:")
    print(f"👤 Username: {name}")
    print(f"📧 Email:    {email}")

if __name__ == "__main__":
    main()
# profile_checker.py
# This script checks the global Git configuration for user name and email.
# It uses subprocess to call git config and retrieves the values.
# If the values are not set, it returns "Not set"..py
# This script checks the global Git configuration for user name and email.
# It uses subprocess to call git config and retrieves the values.
# If the values are not set, it returns "Not set".  