<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Simlan Assembly Language Interpreter</h1>

    <h2>Description</h2>
    <p>The Simlan Assembly Language Interpreter is a simple interpreter written in C that can execute programs written in a custom assembly language called Simlan. It reads Simlan assembly code from a file, interprets and executes the instructions, and produces output accordingly.</p>

    <h2>Example Simlan Assembly Code</h2>

    <h3>Counting from 0 to 9:</h3>
    <pre><code>put 1,r5
put 0,r1
put 10,r2
jmpe r1,r2,8
prn r1
add r5,r1
jmpu 4
halt</code></pre>

    <h3>Calculating 6 factorial:</h3>
    <pre><code>put 0,r2
put 0,r4
put 0,r7
put 1,r6
put 1,r5
put 6,r3
jmpe r2,r3,17
add r5,r2
jmpe r4,r2,13
add r6,r7
add r5,r4
jmpu 9
put 1,r4
put 0,r6
add r7,r6
jmpu 7
prn r7
halt</code></pre>

    <h3>Calculating the summation from 1 to 10:</h3>
    <pre><code>put 0,r1
put 1,r6
put 0,r2
put 10,r3
jmpe r1,r3,9
add r6,r1
add r1,r2
jmpu 5
prn r2
halt</code></pre>

    <h2>Running the Interpreter</h2>
    <ol>
        <li>Clone the repository:
            <pre><code>git clone https://github.com/your-username/simlan-interpreter.git</code></pre>
        </li>
        <li>Compile the code:
            <pre><code>gcc -o simlan-interpreter simlan.c</code></pre>
        </li>
        <li>Run the interpreter:
            <pre><code>./simlan-interpreter Simlan.sla</code></pre>
        </li>
    </ol>

    <h2>Contributing</h2>
    <p>Contributions are welcome! Feel free to submit bug reports, feature requests, or pull requests to help improve the interpreter.</p>

    <h2>License</h2>
    <p>This project is licensed under the MIT License - see the <a href="LICENSE">LICENSE</a> file for details.</p>
</body>
</html>
