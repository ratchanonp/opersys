# Chapter 1 | Pratice Exercises

**1.1** What are the three main purposes of an operating system?

- **Answer:**

  - `Resource Management : Manage the resources of the hardware`
  - `Provide an interface for user : Provide an interface for user to interact with the hardware`
  - `Software Execution Management : Provide an environment for software to execute on the hardware`

**1.2** We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to “waste” resources? Why is such a system not really wasteful?

- **Answer:**
  - **When**
    - `To improve the user experience`
    - `To support real time applications`
    - `To improve security`
  - **Why**
    - `In all of these cases, the benefits of wasting resources outweigh the costs. For example, a GUI may use more resources than a CLI, but it can make the system much easier to use for most people. Real-time applications may need to use more resources than other types of applications, but they are often critical to the safe and efficient operation of essential systems. And security measures may slow down the system, but they can help to protect users from serious harm.`

**1.3** What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

- **Answer:**
  - `The main difficulty is ensuring that the operating system can respond to an event within a strict deadline. This requires careful design and implementation of the operating system.`

**1.4** Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers.

- **Answer:**
  - **Should**
    - `Convenience : It is convenient for the user to have these applications included with the operating system.`
    - `Integration : This can lead to better performance nd more seamlessly user experience.`
    - `Quality : ensuring that the application is high quality and reliable when it is included with the operating system.`
  - **Should not**
    - `Increased complexity : This can lead to more bugs and security vulnerabilities.`
    - `Reduced competition : This can lead to less innovation and higher prices. very difficult to vender to compete with the operating system vendor.`
    - `Vendor lock-in : This can make it difficult for users to switch to a different operating system.`

**1.5** How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?
- **Answer:**
    - `The distinction between kernel mode and user mode provides a rudimentary form of protection in the following manner. Certain instructions could be executed only when the CPU is in kernel mode. Thus, the kernel mode is protected from errant users, and users are protected from one another.`

**1.6** Which of the following instructions should be privileged?

a. Set value of timer. `Privileged`

b. Read the clock. `Unprivileged`

c. Clear memory. `Privileged`

d. Issue a trap instruction. `Privileged`

e. Turn off interrupts. `Privileged`

f. Modify entries in device-status table. `Privileged`

g. Switch from user to kernel mode. `Privileged`

h. Access I/O device. `Privileged`
