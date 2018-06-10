# Enigma Machine
Enigma Machine Sim

Now we are working in convert this program in a command line tool.

## Install/ Compile

In the shell on the directory path write: 
```
  $ git clone https://github.com/jeffrey-chan/enigma.git
  $ cd enigma 
  $ make all
```

## Getting Started
```
$ ./enigma
Enigma Machine Simulator  by Jeffrey Chan
Please set Rotor I, II and III with letter A-Z [English Keyboard]
Set RotorI -> Q
Set RotorII -> W
Set RotorIII -> R

Enigma Machine Only allows enter letter A-Z [English Keyboard] No numbers.
Press [0] to exit.
Press [1] to set rotors again.
Press [2] to set plugboard.
Message : Secret Message
PKQHBLTTBBHDB
0
```

### Set Rotors

This Enigma Machine Simulator have 3 Rotors each need to be set initialized to a letter. Example Rotor I -> Q, Rotor II -> W, Rotor III -> E. Remember to decipher the message all rotors has to be the same when the message encripted.

```
Please set Rotor I, II and III with letter A-Z [English Keyboard]
Set RotorI -> Q
Set RotorII -> W
Set RotorIII -> R
```

### Setting the PlugBoard

The unique require to start to encript message in Enigma Machine Sim is set the three rotors, but if you want to add more "security" to your encrypeted message you can use the plugboard. What is the plugboard? The plugboard allow you interchange letter between them example A to Z and Z to A. The old Enigma makes this through wires, that is why before interchange letter ask you how many wire you want? 
Remeber to decipher the code you will need has the same rotors setting and Plugboard setting at when the message encripted.

```
$ ./enigma
...
...
Message : 2
Setting PlugBoard :
How many plug wire do you want? (0 - 13) -> 3
Wire #1
First letter -> Z
Second letter -> A
Wire #2
First letter -> G
Second letter -> O
Wire #3
First letter -> P
Second letter -> R
Message : Secret Message
```
# Now you can Encrypt Message

*note: This Enigma machine do not accept Numbers, space and other characters except a-z & A-Z in english language.
