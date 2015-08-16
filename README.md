# Simple test for dtoa from David M. Gay

This is a simple test script in C for dtoa. It can be compiled
using `make` command.

## Results

These are results from dtoa-test at commit
[e1ffc0b7](https://github.com/bukka/dtoa/blob/e1ffc0b7d29e7d50a1649cbcc9612e85264163e3/dtoa-test.c)

```
DBL_DIG: 15

 m |    | 0.5 in C                                                | sign | decpt
 0 |  0 | 5                                                       |    0 |     0
 2 | 17 | 5                                                       |    0 |     0
 2 | 50 | 5                                                       |    0 |     0

 m |    | 0.9999 in C                                             | sign | decpt
 0 |  0 | 9999                                                    |    0 |     0
 2 | 17 | 99990000000000001                                       |    0 |     0
 2 | 50 | 99990000000000001101341240428155288100242614746094      |    0 |     0

 m |    | 0.9999999999999999 in C                                 | sign | decpt
 0 |  0 | 9999999999999999                                        |    0 |     0
 2 | 17 | 99999999999999989                                       |    0 |     0
 2 | 50 | 99999999999999988897769753748434595763683319091797      |    0 |     0

 m |    | 0.00001234567890123456789 in C                          | sign | decpt
 0 |  0 | 12345678901234568                                       |    0 |    -4
 2 | 17 | 12345678901234568                                       |    0 |    -4
 2 | 50 | 12345678901234567807461764421539385239157127216458      |    0 |    -4

 m |    | -12323.23422134233 in C                                 | sign | decpt
 0 |  0 | 1232323422134233                                        |    1 |     5
 2 | 17 | 12323234221342331                                       |    1 |     5
 2 | 50 | 12323234221342330783954821527004241943359375            |    1 |     5

 m |    | 123232394239048932930489349234903422134233.1 in C       | sign | decpt
 0 |  0 | 12323239423904892                                       |    0 |    42
 2 | 17 | 12323239423904892                                       |    0 |    42
 2 | 50 | 123232394239048924354070805890414923481088              |    0 |    42

 m |    | 6.0 / 3.0                                               | sign | decpt
 0 |  0 | 2                                                       |    0 |     1
 2 | 17 | 2                                                       |    0 |     1
 2 | 50 | 2                                                       |    0 |     1

 m |    | 0.908234 / 0.293023323234                               | sign | decpt
 0 |  0 | 30995280170060404                                       |    0 |     1
 2 | 17 | 30995280170060404                                       |    0 |     1
 2 | 50 | 3099528017006040414571543806232511997222900390625       |    0 |     1
```
