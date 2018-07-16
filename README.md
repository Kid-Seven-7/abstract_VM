# Abstract VM

###### by Kid-Seven-7

> The first project in the C++ module.
>A simplified Virtual Machine that takes in ASM instructions to
perform simple arithmetics

Abstract VM is a program that allows the user to perform simple arithmetics in pseudo assembly.

Instructions that can be performed include:
>push- To push a value onto the stack ``push int8(42)``
>
>pop- To remove a value from the stack ``pop``
>
>print- To display the ASCII representation of a value, must be an int8 from 32- 126 ``print``
>
>dump- To output all value currently on the stack, starting with the top most value ``dump``
>
>add- Pop the two top most values, adds them and pushes their sum ``add``
>
>sub- Pop the two top most values, subtracts them and pushes result ``add``
>
>mul- Pop the two top most values, multiples them and pushes their product ``add``
>
>div- Pop the two top most values, divides them and pushes the result ``add``
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
	* we think code_ Beta
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

## Coggle Mind map
[Coggle mind map](https://coggle.it/diagram/WzRwAjCAbm_AquTD/t/-/d49927e3c2dbe46a62877a4fdb3ee68991934e750fef93495c036af75906a4c9)

## Contributing

Not open to contributing at present
