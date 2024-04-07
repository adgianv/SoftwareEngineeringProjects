# MINITALK

To compile the program, use `make re` in your command line.

### Running the Program

1. Start the server:
    ```bash
    ./server
    ```

2. Note the PID number (4 digits) displayed.

3. Open a new terminal window.

4. Navigate to the Minitalk repository and execute:
    ```bash
    ./client "PID NUM" "SAMPLE MESSAGE"
    ```

   Replace `"PID NUM"` with the server's PID number and `"SAMPLE MESSAGE"` with your desired message. No quotes are needed.

5. You will see a *"*message received"** message on screen and the message will appear in the terminal window running the server.

---

**_Note:_** The program supports emoticons and long messages.








