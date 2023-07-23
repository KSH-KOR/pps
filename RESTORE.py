import os

def restore_file_names():
    current_dir = os.getcwd()
    files = os.listdir(current_dir)

    for file_name in files:
        if os.path.isfile(file_name):
            base_name, extension = os.path.splitext(file_name)
            parts = base_name.split('_')
            if len(parts) == 3:
                prefix = parts[0]
                name = parts[1]
                date = parts[2]
                new_file_name = f"{prefix}_{name}_{date}{extension}"
                os.rename(file_name, new_file_name)

# Example usage
restore_file_names()
