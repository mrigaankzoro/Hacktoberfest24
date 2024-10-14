import os

# Define the paths to the files on external storage
file1_path = '/path/to/external/storage/file1.txt'
file2_path = '/path/to/external/storage/file2.txt'
merged_file_path = '/path/to/external/storage/merged_file.txt'

# Merge the files
def merge_files(file1, file2, merged_file):
    with open(merged_file, 'w') as outfile:
        for fname in [file1, file2]:
            with open(fname) as infile:
                outfile.write(infile.read())
                outfile.write('\n')  # Optional: add a newline between files

merge_files(file1_path, file2_path, merged_file_path)
print(f'Merged {file1_path} and {file2_path} into {merged_file_path}.')

# If you want to provide a download link (for web applications)
# You can use a web framework like Flask to serve the file
# Here's a simple Flask example:

from flask import Flask, send_file

app = Flask(__name__)

@app.route('/download')
def download_file():
    return send_file(merged_file_path, as_attachment=True)

if __name__ == '__main__':
    app.run(debug=True)
