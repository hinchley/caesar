# Caesar Cipher
## Overview
This program is an implementation of the Caesar Cipher.

https://en.wikipedia.org/wiki/Caesar_cipher

The following steps are performed during encryption:
- Read the plain text input string.
- Remove all non-alpha characters from the string.
- Convert any lower case characters to upper case.
- Apply the cipher.
- Display the encrypted text.

## Build
Use the following command to build the program:
```
./build.sh
```

## Usage
To encrypt a string:
```
./caesar -e "STRING TO ENCRYPT"
```

The above command returns:
```
VWULQJWRHQFUBSW
```

To decrypt a string:
```
./caesar -d VWULQJWRHQFUBSW
```

The above command returns:
```
STRINGTOENCRYPT
```