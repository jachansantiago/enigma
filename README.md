# Enigma Machine
Enigma Machine Sim

Now we are working in convert this program in a command line tool.

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


# Message requirements
*This Enigma machine do not accept Numbers and other characters except a-z & A-Z in english language.
