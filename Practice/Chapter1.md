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

**a.** Set value of timer. `Privileged`

**b.** Read the clock. `Unprivileged`

**c.** Clear memory. `Privileged`

**d.** Issue a trap instruction. `Privileged`

**e.** Turn off interrupts. `Privileged`

**f.** Modify entries in device-status table. `Privileged`

**g.** Switch from user to kernel mode. `Privileged`

**h.** Access I/O device. `Privileged`

**1.7** Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that you think could arise with such a scheme.

- **Answer:**
  - `The operating system would not be able to modify itself, so it would not be able to fix bugs or add new features.`
  - `Difficuly to store critical data in the memory partition. Such as password, encryption key may be stored in the unprotected memory partition.`

**1.8** Some CPUs provide for more than two modes of operation.What are two possible uses of these multiple modes?

- **Answer:**
  - `Virtualization : allow multiple operating systems to run on the same hardware.`
  - `Fine-grained security : provide more granular level of control over the privileges granted to a process.`

**1.9** Timers could be used to compute the current time. Provide a short description of how this could be accomplished.

- **Answer:**
  `how to compute the current time using a timer interrupt:`

  `- Start a timer.`

  `- Wait for the timer to interrupt the CPU.`

  `- Read the current value of the timer counter.`
  
  `- The current value of the timer counter is the current time.`

**1.10** Give two reasons why caches are useful. What problems do they solve? What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?

- **Anser:**
  - **Reasons**
    - `Improved performance : solve the performance problem by providing faster access to data than the main memory.`
    - `Reduced power consumption : solve the power consumption problem by reducing the number of times that the CPU needs to access the main memory.`
  - **Problems they solve**
    - `Memory hierarchy : solve the memory hierarchy problem by providing a small amount of fast memory that can be accessed much more quickly than the main memory.`
    - `Locality : solve the locality problem by storing recently accessed data in the cache.`
  - **Problems they cause**
    - `Increased complexity : Caches add complexity to the system. Operating systems and applications must be aware of the existence of caches and must be careful to ensure that data is properly synchronized between the cache and the main memory.`
    - `Increased cost : Cache is more expensive than main memory.`
  - **If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk), why not make it that large and eliminate the device?**
    - `Cost : Caches are typically much more expensive than the main memory or other storage devices`
    - `Power consumption : caches need to be constantly powered on so that they can be accessed quickly.`

**1.11** Distinguish between the client–server and peer-to-peer models of distributed systems.

- **Answer:**
  | Characteristic | Client–server | Peer-to-peer |
  | :---: | :---: | :---: |
  | Number of systems | 2 | 2 or more |
  | Centralized | Centralized | Decentralized |
  | Node roles | Client or server | All nodes are equal |
  | Resource sharing | Server provides resources to clients | All nodes share resources |
  | Service provision | Server provides services to clients | All nodes provide services to each other |
