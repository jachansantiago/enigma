# Enigma

## Introduction
This repository contains an enigma machine simulator as command line tool. The enigma machine was one of the first encryption devices used to hide military messages during wars. This machine can encode a message, and it's able to decode the encoded message using the same configuration with was encoded. 

Enigma has two essential components **rotors** and the **plugboard**.  The rotors change in when pressing a key this is made more difficult to decode. Plugboard only interchange letters between them.  To encode a message the rotors and plugboard need to be set. To set the rotors, a letter needs to be assigned to each rotor. This simulator only has three rotors.  The plugboard configuration consists of pairs of letters, and each letter has a one-to-one relationship. An example [A-F, H-K, L-O], [A-S, H-J], [] are valid configurations [A-G, G-H] isn't. To decode a message the rotor and plugboard configuration has to be the same. For more information about Enigma machine [click here](https://youtu.be/G2_Q9FoD-oQ). 

## Security
Until Alan Turing built a machine to decode the Enigma Machine this algorithm was safe. Now with a computer is easier to crack this encryption. More information about crack enigma [click here](https://www.youtube.com/watch?v=V4V2bpZlqx8).

## Install

In the shell on the directory path write: 
```
  $ git clone https://github.com/jeffrey-chan/enigma.git
  $ cd enigma 
  $ make all
```

## Getting Started
#### Encrypt 
```
$./enigma -m "my secret message" -r QWR -p AZGOPR
FL FJGVJE DHFJUVJ
```
##### Options
  * -m <_your message_>: message to decode or encode. 
  * -r _ABC_ (**required**) : Tree letters A, B, and C where Rotor I is to A, Rotor II to B, and Rotor III to C
  * -p _<letter pairs>_ : Pairs of letters that are interchange in the plugboard.
  
In this example encode the message _"my secret message"_ using the following configuration:

  * Rotor:
    * Rotor I set to Q
    * Rotor II set to W
    * Rotor III set to R
  * PlugBoard:
    * A and Z are interchanged
    * G and O are interchanged
    * P and R are interchanged

#### Decrypt (WRONG)
```
$./enigma -m "FL FJGVJE DHFJUVJ" -r QWR 
MY SEQPET MESSZOE
```
_Note that if the message was encrypted with plugboard configuration, to decrypt the message need the same configuration._
#### Decrypt
```
$./enigma -m "FL FJGVJE DHFJUVJ" -r QWR -p AZGOPR
MY SECRET MESSAGE
```

## Deals with files
* -f <_input filename_>
* -o <_output filename_>

```
$./enigma -r QWR -f input_file.txt
RKRUC HXKTA.
$./enigma -m "RKRUC HXKTA." -r QWR -o output_file.txt
```

## Message requirements
_This Enigma machine do not accept Numbers and other characters except a-z & A-Z in english language._

## LICENSE
Enigma is released under the [MIT license](https://github.com/jeffrey-chan/enigma/blob/master/LICENSE).
