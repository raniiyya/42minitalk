# Minitalk

**Minitalk** is a communication program developed as part of the 42 curriculum. It demonstrates inter-process communication (IPC) in Unix systems using signals. The project consists of a server and a client, allowing the transmission of messages one character at a time.

---

## Features

- **Client-Server Communication**: The client sends a message to the server, which then displays it.
- **Signal Handling**: Implements custom handlers for `SIGUSR1` and `SIGUSR2` signals to encode and decode data.
- **Error Management**: Handles errors such as invalid inputs or unreachable processes gracefully.
- **Custom Protocol**: Encodes characters as a series of signals to ensure reliable communication.

---

## Technologies Used

- **Language**: C
- **System Calls**: `kill`, `signal`, `pause`, `usleep`, etc.
- **Operating Systems**: Linux and macOS
- **Makefile**: For automated compilation.

---

## How to Run

### Prerequisites

- A Unix-based system (Linux or macOS).
- A C compiler (e.g., `gcc`).

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/minitalk.git
   cd minitalk
2. Compile the project
   ```bash
   make
   ```
   The server will display its Process ID (PID). Note this PID for the client.
3. Start the server
   ```bash
   ./server
4. Send a message using the client
   ```bash
   ./client <server_pid> "Your message here"
   ```
   Replace `<server_pid>` with the PID displayed by the server.

---

## How It Works

1. The **server** runs continuously, waiting for incoming signals.
2. The **client** sends characters to the server by encoding them as binary using `SIGUSR1` (0) and `SIGUSR2` (1) signals.
3. The **server** decodes the signals and reconstructs the original message, displaying it in the terminal.

---

## Project Rules

- The project uses only `SIGUSR1` and `SIGUSR2` for communication.
- Signal-based communication ensures minimal CPU usage through pause() and usleep() calls.
- The server must handle multiple messages consecutively without restarting.

---

## License

This project is for educational purposes under the 42 Network. Redistribution is prohibited without prior authorization.
