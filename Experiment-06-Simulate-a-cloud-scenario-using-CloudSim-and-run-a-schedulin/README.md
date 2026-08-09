# 6. Simulate a cloud scenario using CloudSim and run a scheduling algorithm not present in CloudSim

## Aim

To simulate a cloud scenario using CloudSim and run a scheduling algorithm that is not present in CloudSim.

## Procedure

**To use CloudSim in Eclipse:**

**Step 1: Download CloudSim**

Download the CloudSim installable files from the [CloudSim downloads page](https://code.google.com/archive/p/cloudsim/downloads) and unzip.

**Step 2: Open Eclipse**

**Step 3: Create a new Java Project**

`File -> New -> Java Project`

**Step 4: Import CloudSim**

Import the unpacked CloudSim project into the new Java Project.

**Step 5: Initialize the CloudSim package**

The first step is to initialize the CloudSim library:

```java
CloudSim.init(num_user, calendar, trace_flag);
```

**Step 6: Create the Datacenter**

Data centres are the resource providers in CloudSim, so creating a data centre is the second step. To create a `Datacenter`, you need a `DatacenterCharacteristics` object that stores the properties of the data centre, such as architecture, OS, list of machines, allocation policy (time- or space-shared), time zone, and price:

```java
Datacenter datacenter0 = new Datacenter(name, characteristics, new VmAllocationPolicySimple(hostList));
```

**Step 7: Create a broker**

The third step is to create a broker:

```java
DatacenterBroker broker = createBroker();
```

**Step 8: Create a virtual machine**

The fourth step is to create a virtual machine, specifying: unique ID of the VM, userId (ID of the VM's owner), mips, number of Pes (amount of CPUs), amount of RAM, amount of bandwidth, amount of storage, virtual machine monitor, and cloudlet scheduler policy for cloudlets:

```java
Vm vm = new Vm(vmid, brokerId, mips, pesNumber, ram, bw, size, vmm, new CloudletSchedulerTimeShared());
```

**Step 9: Submit the VM list to the broker**

```java
broker.submitVmList(vmlist);
```

**Step 10: Create a cloudlet**

Create a cloudlet with length, file size, output size, and utilization model:

```java
Cloudlet cloudlet = new Cloudlet(id, length, pesNumber, fileSize, outputSize,
        utilizationModel, utilizationModel, utilizationModel);
```

**Step 11: Submit the cloudlet list to the broker**

```java
broker.submitCloudletList(cloudletList);
```

**Step 12: Start the simulation**

```java
CloudSim.startSimulation();
```

The full outline of these steps is available in [code/CloudSimExample1.java](code/CloudSimExample1.java).

## Sample Output

Sample output from running the existing `CloudSimExample1`:

```
Starting CloudSimExample1...
Initialising...
Starting CloudSim version 3.0
Datacenter_0 is starting...
Broker is starting...
Entities started.
0.0: Broker: Cloud Resource List received with 1 resource(s)
0.0: Broker: Trying to Create VM #0 in Datacenter_0
0.1: Broker: VM #0 has been created in Datacenter #2, Host #0
0.1: Broker: Sending cloudlet 0 to VM #0
400.1: Broker: Cloudlet 0 received
400.1: Broker: All Cloudlets executed. Finishing...
400.1: Broker: Destroying VM #0
Broker is shutting down...
Simulation: No more future events
CloudInformationService: Notify all CloudSim entities for shutting down.
Datacenter_0 is shutting down...
Broker is shutting down...
Simulation completed.
Simulation completed.

========== OUTPUT ==========
Cloudlet ID    STATUS    Data center ID    VM ID    Time    Start Time    Finish Time
0              SUCCESS   2                 0        400     0.1           400.1

*****Datacenter: Datacenter_0*****
Userid    Debt
3         35.6

CloudSimExample1 finished!
```
