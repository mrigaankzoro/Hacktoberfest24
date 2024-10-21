# CPU Scheduling Algorithms

## Overview

CPU scheduling is the process of determining which process in a multi-tasking environment should be executed by the CPU at a given time. The goal of CPU scheduling is to maximize CPU utilization and improve the efficiency of system performance. The choice of scheduling algorithm can significantly affect the system's overall performance, especially in time-sharing systems.

## Types of Scheduling Algorithms

### Non-Preemptive Scheduling
Non-preemptive scheduling is a type of scheduling where a running process is not interrupted; it runs to completion once it has started. In other words, the CPU is allocated to a process, and it remains allocated until the process completes or voluntarily gives up the CPU. Non-preemptive algorithms are simple but may lead to longer waiting times for some processes.

### Preemptive Scheduling
In preemptive scheduling, a running process can be interrupted and moved back to the ready queue if a higher-priority process arrives or the time slice allocated to the running process expires. This allows the CPU to switch between processes and improves the system's responsiveness. However, preemptive algorithms are more complex to implement compared to non-preemptive algorithms.

## Key Terms in CPU Scheduling

### Arrival Time
- **Definition**: The time at which a process enters the ready queue and is available for execution.
- **Importance**: It helps determine when a process is eligible to start execution.

### Waiting Time
- **Definition**: The total time a process spends in the ready queue waiting for CPU allocation.
- **Formula**: `Waiting Time = Turnaround Time - Burst Time`
- **Importance**: Minimizing waiting time can lead to more efficient CPU utilization.

### Turnaround Time
- **Definition**: The total time taken from the arrival of the process to its completion.
- **Formula**: `Turnaround Time = Completion Time - Arrival Time`
- **Importance**: A lower turnaround time improves the responsiveness of the system.

## Common CPU Scheduling Algorithms

### 1. First-Come, First-Served (FCFS)
- **Type**: Non-Preemptive
- **Description**: Processes are executed in the order they arrive in the ready queue. Once a process starts executing, it runs to completion.
- **Pros**: Simple to implement.
- **Cons**: Can lead to the "convoy effect," where shorter processes wait for a long time if a long process is being executed.

### 2. Shortest Job First (SJF)
- **Type**: Non-Preemptive
- **Description**: The process with the shortest burst time is selected for execution next. If two processes have the same burst time, FCFS is used to break the tie.
- **Pros**: Minimizes average waiting time.
- **Cons**: Requires accurate estimation of burst times, and longer processes may suffer from starvation.

### 3. Non-Preemptive Priority Scheduling
- **Type**: Non-Preemptive
- **Description**: Each process is assigned a priority, and the process with the highest priority is executed first. If two processes have the same priority, FCFS is used as a tie-breaker.
- **Pros**: Can be used to implement different levels of importance for processes.
- **Cons**: Lower-priority processes may suffer from starvation.

### 4. Shortest Remaining Time First (SRTF)
- **Type**: Preemptive
- **Description**: A preemptive version of SJF. The process with the shortest remaining burst time is executed next, and if a new process with a shorter burst time arrives, the current process is preempted.
- **Pros**: Provides better average turnaround time compared to SJF.
- **Cons**: Requires accurate burst time estimates and can be complex to implement.

### 5. Round Robin (RR)
- **Type**: Preemptive
- **Description**: Each process is assigned a fixed time slice, called a time quantum, during which it can execute. If a process does not complete within its time quantum, it is moved to the back of the queue, and the next process is executed.
- **Pros**: Ensures fairness and prevents starvation by allocating time slices to each process.
- **Cons**: Performance is heavily dependent on the choice of the time quantum. Too small a quantum leads to high context-switching overhead, while too large a quantum behaves like FCFS.

## Summary Table

<table border='3'>
    <tr>
        <td>Algorithm</td>
        <td>Type</td>
        <td>Description</td>
        <td>Pros</td>
        <td>Cons</td>
    </tr>
    <tr>
        <td>First-Come, First-Served (FCFS)</td>
        <td>Non-Preemptive</td>
        <td>Processes are executed in the order of arrival.</td>
        <td>Simple to implement</td>
        <td>Can lead to long waiting times for shorter processes</td>
    </tr>
    <tr>
        <td>Shortest Job First (SJF)</td>
        <td>Non-Preemptive</td>
        <td>Executes the process with the shortest burst time.</td>
        <td>Minimizes average waiting time</td>
        <td>Requires accurate burst time estimation</td>
    </tr>
    <tr>
        <td>Non-Preemptive Priority</td>
        <td>Non-Preemptive</td>
        <td>Executes the process with the highest priority.</td>
        <td>Supports priority-based execution</td>
        <td>Lower-priority processes may starve</td>
    </tr>
    <tr>
        <td>Shortest Remaining Time First</td>
        <td>Preemptive</td>
        <td>Executes the process with the shortest remaining burst time.</td>
        <td>Better average turnaround time than SJF</td>
        <td>Complex implementation, requires burst time estimation</td>
    </tr>
    <tr>
        <td>Round Robin (RR)</td>
        <td>Preemptive</td>
        <td>Each process gets a fixed time slice for execution.</td>
        <td>Ensures fairness and prevents starvation</td>
        <td>Performance depends on the choice of time quantum</td>
    </tr>
</table>

## Conclusion

CPU scheduling plays a crucial role in optimizing the performance of multi-tasking operating systems. Different algorithms have their advantages and disadvantages, and the choice of algorithm depends on the system's requirements and workload characteristics.
