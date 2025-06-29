# import os

# def list_mp4_files(folder_path, output_file_path):
#     # Create the output directory if it doesn't exist
#     os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

#     with open(output_file_path, 'w', encoding='utf-8') as output_file:
#         for root, dirs, files in os.walk(folder_path):
#             for file in files:
#                 if file.lower().endswith('.mp4'):
#                     full_path = os.path.join(root, file)
#                     output_file.write(full_path + '\n')
#                     print(".")

#     print(f"\n✅ MP4 file list saved to:\n{output_file_path}")

# # Example usage
# if __name__ == "__main__":
#     # folder_to_search = input("📁 Enter the path of the folder to search: ").strip('"')
#     # output_path = input("📄 Enter the path of the output .txt file: ").strip('"')
#     # folder_to_search = input("F:\Movies").strip('"')
#     # output_path = input("F:\mp4_list.txt").strip('"')
#     folder_to_search = r"F:\Movies"
#     output_path = r"F:\mp4_list.txt"
#     list_mp4_files(folder_to_search, output_path)





import os

def list_mp4_files(folder_path, output_file_path):
    # Ensure the output directory exists
    os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

    # Derive second output file path
    name_only_path = os.path.join(os.path.dirname(output_file_path), "mp4_name.txt")

    # Open both files
    with open(output_file_path, 'w', encoding='utf-8') as full_file, \
         open(name_only_path, 'w', encoding='utf-8') as name_file:

        count = 0
        for root, dirs, files in os.walk(folder_path):
            for file in files:
                if file.lower().endswith('.mp4'):
                    full_path = os.path.join(root, file)
                    name_no_ext = os.path.splitext(file)[0]

                    full_file.write(full_path + '\n')
                    name_file.write(name_no_ext + '\n')

                    print(f"🟢 Found: {name_no_ext}")
                    count += 1

    print(f"\n✅ {count} MP4 files saved to:\n- {output_file_path}\n- {name_only_path}")

# Example usage
if __name__ == "__main__":
    folder_to_search = r"F:\Movies"
    output_path = r"F:\mp4_list.txt"
    list_mp4_files(folder_to_search, output_path)