import subprocess

def run_cpp_with_input(cpp_file, input_file):
    # Compile the C++ file
    compilation_process = subprocess.run(['g++', cpp_file], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    # Check if compilation was successful
    if compilation_process.returncode == 0:
        print("Compilation successful")
        
        # Open the input file
        with open(input_file, 'r') as f:
            input_data = f.readline()
        
        # Run the compiled C++ executable with input from the input file
        execution_process = subprocess.run('./a.exe', input=input_data.encode(), text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        
        # Print the output
        print(execution_process.stdout)
        
        # Print any errors
        if execution_process.stderr:
            print("Errors:", execution_process.stderr)
    else:
        print("Compilation failed")
        print("Errors:", compilation_process.stderr)

# Replace 'example.cpp' and 'input.txt' with your own file names
run_cpp_with_input('.\\1_1.cpp', '.\\1_1.txt')
