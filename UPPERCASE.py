import os

def rename_files_to_uppercase():
    current_dir = os.getcwd()
    files = os.listdir(current_dir)

    for file_name in files:
        if os.path.isfile(file_name):
            base_name, extension = os.path.splitext(file_name)
            new_base_name = base_name.upper()
            new_file_name = new_base_name + extension
            os.rename(file_name, new_file_name)

# Example usage
rename_files_to_uppercase()
