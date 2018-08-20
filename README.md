# Abstract VM
![alt text](https://www.google.co.za/imgres?imgurl=https%3A%2F%2Fimages.pexels.com%2Fphotos%2F67636%2Frose-blue-flower-rose-blooms-67636.jpeg%3Fauto%3Dcompress%26cs%3Dtinysrgb%26h%3D350&imgrefurl=https%3A%2F%2Fwww.pexels.com%2Fsearch%2Fflower%2F&docid=5UbOpOqf9qM23M&tbnid=ZAXhvwKefKr6jM%3A&vet=10ahUKEwib5ovAxfvcAhUsDcAKHaSWBlIQMwiyASgAMAA..i&w=528&h=350&bih=1006&biw=1920&q=image&ved=0ahUKEwib5ovAxfvcAhUsDcAKHaSWBlIQMwiyASgAMAA&iact=mrc&uact=8)
###### the first project of the C++ module at [we think code_](https://www.wethinkcode.co.za/)

>A simplified Virtual Machine that takes in ASM instructions to
perform simple arithmetics

Abstract VM is a program that allows the user to perform simple arithmetics in pseudo assembly.

Instructions that can be performed include:
>push- To push a value onto the stack ``push int8(42)``
>
>assert- Compares the passed value to that on top of the stack ``assert int8(42)``
>
>pop- To remove a value from the stack ``pop``
>
>print- To display the ASCII representation of a value, must be an int8 from 32- 126 ``print``
>
>dump- To output all value currently on the stack, starting with the top most value ``dump``
>
>add- Pop the two top most values, adds them and pushes their sum ``add``
>
>sub- Pop the two top most values, subtracts them and pushes result ``sub``
>
>mul- Pop the two top most values, multiples them and pushes their product ``mul``
>
>div- Pop the two top most values, divides them and pushes the result ``div``
>
>mod- Pop the two top most values, divides them and pushes the remainder ``mod``
>
>exit- Ends the current instruction set ``exit``
>

## Installation

iOS X & Linux:

```sh
git clone https://github.com/Kid-Seven-7/abstract_VM.git
make
```

Windows:

```sh
git clone https://github.com/Kid-Seven-7/abstract_VM.git
make
```

## Usage example

With file ``./avm [filename] [flags] ``

with the stdin ``./avm [flags] ``

Flags ``-v (Verbose), -e (shaow all errors)``

## Release History

* 0.0.2
	* In progress
* 0.0.1
  * we think code_ version

## Contributors

**Joseph Ngoma**
>[Linkedin](https://www.linkedin.com/in/joseph-ngoma-03189214b/)
>
>[Github](https://github.com/Kid-Seven-7)
>
>[Twitter](https://twitter.com/mr_joey0707)
>

## Contributing

Not open to contributing at present
