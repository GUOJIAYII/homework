





$\because$ Positional Notation $${(x)}_{2} = \sum_{i=1}^{k}d_{i}2^{i-1}$$  

$\because$ Two's complement 

$$N(x) = 2^{k} - x$$, where k is the number of bits for an integer

and, $$N'(x) = 2^{m} - x$$ where $$m > k$$

$\therefore$ $$N'(x) = 2^{m} - x = (2^{m} - 2^{k}) +  2^{k} - x = (2^{m}-1) - (2^{k}-1) + N(x)$$

$\because$ $$2^{m}-1 = (2-1)\sum_{i=1}^{m}2^{i-1}$$, that is m bits 1. So the same, $$(2^{k}-1)$$ is k bits 1

$\therefore$ If N(x) is a negative binary integer, the most-significant bit can be repeated in all the extra bits 

$\blacksquare$ 

