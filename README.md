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
