import subprocess
import os

def compilation(verbose = False) -> None:
  result = subprocess.run(["make"])
  if result.returncode != 0:
    if verbose:
      print("Compilation failed ❌ !")
    return
  else : 
    if verbose:
      print("Compilation successful ✅ !")

def test_all_files(verbose = False) -> None:
  test_dir = "./test_txt"
  all_passed = True

  for filename in sorted(os.listdir(test_dir)):
    if filename.endswith(".txt"):
      filepath = os.path.join(test_dir, filename)

      result = subprocess.run(
        ["./bin/main.exe", filepath],
        capture_output=True,
        text=True
      )

      with open(filepath, "r") as file:
        expected_output = file.readline().strip()

      output = result.stdout

      actual_output = None
      for line in output.splitlines():
        if "#" in line:
          actual_output = line.strip()
          break

      if verbose:
        print(f"\n=== Running {filename} ===")
        print(f"Expected: {expected_output}")
        print(f"Actual: {actual_output}")
        if actual_output == expected_output:
          print("Test passed ✅ !")
        else:
          print("Test failed ❌ !")

      if actual_output != expected_output:
        all_passed = False
      

  if all_passed:
    print("\nAll tests passed ✅ !")
  else:
    print("\nSome tests failed ❌ !")