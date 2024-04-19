# simple-vigenere
Vigenère Cypher implementation in C.

## Compilation
```bash
$ gcc vigenere.c -ansi -Wall -o vigenere
```

## Usage
```
./vigenere [-d | -e] PLAINTEXT KEY

-e: encrypt mode
-d: decrypt mode
```

## Sample

```
$ ./vigenere -e plaintextmessagetest anykey                                           
PYYSRREKRWIQSNEOXCSG

$ ./vigenere -d PYYSRREKRWIQSNEOXCSG anykey                                            
PLAINTEXTMESSAGETEST
```

## Observations
Only alphabetical characters are allowed.
