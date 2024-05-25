# Logic Gates Editor

Another revision of a Logic Gates Editor. This time, I'm working with QT6. We'll see how that 
works out for me in the end. I tried in imgui, and I found that immediate mode just wasn't 
fitting for what I'm trying to do. We're connecting Nodes with cables, or connections.

---

### Logic Gates Project

The main purpose of this project is for me to have a way of debugging some save files I'm generating
in my Unreal Engine 5 project, [LogicGates](https://github.com/Inversederivative/LogicGates/)


When I originally got this build, I made some changes, to get a few nodes displaying. I tried to
include my current iteration of the LogicGates [AbstractLogicGates](https://github.com/John-Hatton/AbstractLogicCircuits) library, but it seems to be
completely obscelete, and really only hangs around as a storage location for edge cases. I went
ahead to build another library, which aimed to fix my main problem with building memory systems,
which was [TriStateLogicGates](https://github.com/John-Hatton/TristateLogicCircuits). This project
worked okay, but was simply an extension of the AbstractLogicGates project.

Things finally began to take shape for the feasibility of the project, when I was introduced to
the concept of the observer pattern. I implemented a simple version of this [here](https://github.com/inversederivative/DesignPatterns/tree/main/BehavioralPatterns/Observer)
I then began to adapt it to handle LogicGates.

This lead to the project [LogicGatesAndEvents](https://github.com/inversederivative/LogicGatesAndEvents). This project
seemed to be a good enough implementation, because after some work and adaptation, I was able to
copy and paste nearly all of the code into my Unreal Engine Project:

#### [LogicGates](https://github.com/inversederivative/LogicGates) (Unreal Engine Project)

---

### JSON Files

This project is going quite well and I've implemented a form of JSON serialization/deserialization.
This gives me an interesting interface, with which I can create Nodes in my 2d LogicGates_Editor.

My json files look something like this:

##### Power Source Node JSON Example

    {
        "nodeName": "PowerSource",
        "serialNumber": 86,
        "powerSourceState": "OFF",
        "position":
        {
            "x": -403.78379230891375,
            "y": -597.10820848166929,
            "z": -0.50000954632503181
        },
        "rotation":
        {
            "pitch": 0,
            "yaw": 0,
            "roll": -0
        },
        "connections": [
            {
                "serialNumber": 77,
                "xOrY": "OutX,InZ"
            }
        ]
    }

I plan on somehow converting this x,y position data to 2d space. (the z doesn't move anyways...)
The rotation can be effectively ignored.

---

