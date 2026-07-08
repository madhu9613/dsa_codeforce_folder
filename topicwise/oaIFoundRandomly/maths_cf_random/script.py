from pathlib import Path

root = Path.cwd()  # Current directory where script is run

for exe_file in root.rglob("*.exe"):
    try:
        exe_file.unlink()
        print(f"Deleted: {exe_file}")
    except Exception as e:
        print(f"Failed: {exe_file} -> {e}")

print("Done!")