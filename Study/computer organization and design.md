# Fundamentals of Computer Design
```
	And now for something completely different
					--- Monty Python's Flying Circus
```

## 1.1 Introduction
Computer technology has made incredible progress in the past half century.In 1945,there were no stored-program computers.

Today,a few thousand dollars will purchase a personal computer that has more performance,more main memory,and more disk  storage than a computer bought in 1965 for $1 million.This rapid rate of improvement has come both from advances in the technology used to build computers and from innovation in computer design.

While technological improvements have been fairly steady,progress arising from better computer architectures has been much less consistent.

> consistent:someone who is `consistent ` always behaves in the same way,has the same attitudes towards people or things,or achieves the same level of success in something.

During the first 25 year of electronic computers,both forces made a major contribution;but beginning in about 1970,computer designers became largely dependent upon intergrated circuit technology.During the 1970s,performance continued to improve at about 25% to 30% per year for the mainframes and minicomputers that dominated the industy.

> mainframe:A `mainframe` or `mainframe computer` is a large powerful computer which can be used by many people at the same time and which can do very large or complicated tasks.

The late 1970s saw the emergence of the microprocessor.The ablility of microprocessor to ride the improvements in integrated circuit technology more closely than the less integrated mainframes and minicomputers led to a higher rate of improvement---roughly 35% growth per year in performance.

This growth rate,combined with the cost advantages of a mass-produced microprocessor,let to an increasing fraction of the computer business being based on microprocessors.In addition,two significant changes in the computer marketplace made it easier than ever before to be commercially successful with a new architecture.First,the virtual elimination of assembly language programming reduced the need for object-code compatibility.Second,the creation of standardized,vendor-independent operating systems,such as UNIX,lowered the cost and risk of bringing out a new architecture.These changes made it possible to successively develop a new set of architectures,called RISC architectures,in the early 1980s.Since the RISC-based microprocessors reached the market in the mid 1980s,these machines have grown in performance at an annual rate of over 50%.

Prior to the mid 1980s,microprocessor performance grouth was largely technology driven and averaged about 35% per year.The increase in growth **since then** is attributable to more advanced architectural ideas.

The effect of this dramatic growth rate has been twofold:
* First,it has significantly enhanced the capability available to computer users.As a simple example,consider the highest-performance workstation announced in 1993,an IBM Power-2 machine.Compared with a CRAY Y-MP supercomputer introduced in 1988(probaly the fastest machine in the world at that point),the worstation offers comparable performance on many floating-point programs and better performance on integer programs for a price that is less than one-tenth of the supercomputer!
* Second,this dramatic rate of improvement has led to the dominance of microprocessor-based computers across the entire range of the computer design.Work-stations and PCs have emerged as major products in the computer industy.Minicomputers,which were traditionally made from off-the-shelf logic or form gate arrays,have been replaced by servers made using microprocessors.Mainframes are slowly being replaced with multiprocessors consisting of small numbers of off-the-shelf microprocessors.Even high-end supercomputers are being built with collections of microprocessors.

> High-end:`High-end` products,especially electronic products,are the most expensive of their kind.

Freedom from compatibility with old designs and the use of microprocessor technology led to a renaissance in computer design,which emphasized both architectural innovation and efficient use of technology improvements.This renaissance is responsible for the higher performance growth--- a rate that is unprecedented in the computer industy.

> If something is `unprecedented`,it has never happened before

This text is about the architectural ideas and accompanying compiler improvements that have made this incredible growth rate possible.

## 1.2 The task of a computer designer
The task the computer designer faces is a complex one: Determine what attributes are important for a new machine,then design a machine to maximize performance while staying within cost constraints.
