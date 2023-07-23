import os
import sys
from datetime import datetime

def add_suffix_to_files(name):
    current_dir = os.getcwd()
    files = os.listdir(current_dir)

    today_date = datetime.now().strftime('%Y%m%d')
    suffix = f'_{name}_{today_date}'

    for file_name in files:
        if os.path.isfile(file_name):
            file_parts = os.path.splitext(file_name)
            new_file_name = file_parts[0] + suffix + file_parts[1]
            os.rename(file_name, new_file_name)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: python program_name.py name')
    else:
        name = sys.argv[1]
        add_suffix_to_files(name)
