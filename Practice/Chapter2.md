# Chapter 2 | Pratice Exercises

**2.1** What is the purpose of system calls?

-   **Answer:**
    -   `Provide an interface to the services made available by an operating system`

**2.2** What is the purpose of the command interpreter? Why is it usually separate from the kernel

-   **Answer:**
    -   `The command interpreter used to read and execute user-specified commands. It is usually separate from the kernel to minimize the size of the kernel, to make development easier, and to make the system more secure. If the command interpreter is a separate program, it is also possible to load different command interpreters at different times.`

**2.3** What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system?

-   **Answer:**
    -   `fork() and exec()`
    -   `fork() is used to create a new process.`
    -   `exec() is used to load a program into the process's address space and to execute that program starting at its first instruction.`

**2.4** What is the purpose of system programs?

-   **Answer:**
    -   `System programs provide a convenient environment for program development and execution.`

**2.5** What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?

-   **Answer:**
    -   **Advantage**
        -   `The main advantage of the layered approach is simplicity of construction and debugging.`
    -   **Disadvantage**
        -   `The disadvantages of the layered approach are that it is not always clear what layer a functionality should be added to and that performance may suffer due to the system having to pass through more layers than necessary.`

**2.6** List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.

-   **Answer:**

    -   `Process management`
        -   ` The operating system manages the creation, execution, and termination of processes.`
        -   Would it be impossible for user-level programs to provide these services? `No`
            -   `Process management requires access to the kernel, which is a privileged mode that only the operating system can access.`
    -   `Memory management`

        -   `The operating system manages the allocation and use of memory.`
        -   Would it be impossible for user-level programs to provide these services? `No`
            -   `Memory management requires access to the hardware memory management unit (MMU), which is a special hardware device that helps the operating system manage memory.`

    -   `File system management`

        -   `The operating system provides a file system for storing and organizing files. `
        -   Would it be impossible for user-level programs to provide these services? `No`
            -   `File system management requires access to the disk, which is a low-level hardware device.`

    -   `Device management (I/O)`

        -   `The operating system manages the hardware devices connected to the computer.`
        -   Would it be impossible for user-level programs to provide these services? `No`
            -   `Device management requires access to the hardware devices themselves, which are typically low-level devices.`

    -   `Security`
        -   `The operating system provides security features to protect the computer from unauthorized access and malicious code.`
        -   Would it be impossible for user-level programs to provide these services? `No`
            -   `Security features require access to the kernel, and they also need to be tightly integrated with the hardware and other system software.`

**2.7** Why do some systems store the operating system in firmware, while others store it on disk?

-   **Answer:**
    -   `Some systems store the operating system in firmware because it is more convenient to do so. For example, embedded systems often store the operating system in firmware because they do not have a disk.`

**2.8** How could a system be designed to allow a choice of operating systems from which to boot?What would the bootstrap program need to do?

-   **Answer:**
    -   **HOW**
        -   `By using a boot loader`
    -   **WHAT would the bootstrap program need to do?**
        `1. A small piece of code known as the bootstrap program or boot loader locates the kernel.`
        `2. The kernel is loaded into memory and started`
        `3. The kernel initializes hardware.`
        `4. The root file system is mounted.`
