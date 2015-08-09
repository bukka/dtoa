# Simple test for David M. Grey dtoa

This is a simple test script in C for dtoa. It can be compiled
using `make` command.

## Results

These are results from commit 19277982ac1cf1f50cea226cab37d2368c535d14

```
 m |   p | 0.5 in C                                                               | sign | decpt
 0 |   0 | 5                                                                      |    0 |     0
 2 |  17 | 5                                                                      |    0 |     0
 2 | 100 | 5                                                                      |    0 |     0

 m |   p | 0.9999 in C                                                            | sign | decpt
 0 |   0 | 9999                                                                   |    0 |     0
 2 |  17 | 99990000000000001                                                      |    0 |     0
 2 | 100 | 9999000000000000110134124042815528810024261474609375                   |    0 |     0

 m |   p | 0.9999999999999999 in C                                                | sign | decpt
 0 |   0 | 9999999999999999                                                       |    0 |     0
 2 |  17 | 99999999999999989                                                      |    0 |     0
 2 | 100 | 99999999999999988897769753748434595763683319091796875                  |    0 |     0

 m |   p | 0.00001234567890123456789 in C                                         | sign | decpt
 0 |   0 | 12345678901234568                                                      |    0 |    -4
 2 |  17 | 12345678901234568                                                      |    0 |    -4
 2 | 100 | 1234567890123456780746176442153938523915712721645832061767578125       |    0 |    -4

 m |   p | -12323.23422134233 in C                                                | sign | decpt
 0 |   0 | 1232323422134233                                                       |    1 |     5
 2 |  17 | 12323234221342331                                                      |    1 |     5
 2 | 100 | 12323234221342330783954821527004241943359375                           |    1 |     5

 m |   p | 123232394239048932930489349234903422134233.1 in C                      | sign | decpt
 0 |   0 | 12323239423904892                                                      |    0 |    42
 2 |  17 | 12323239423904892                                                      |    0 |    42
 2 | 100 | 123232394239048924354070805890414923481088                             |    0 |    42

 m |   p | 6.0 / 3.0                                                              | sign | decpt
 0 |   0 | 2                                                                      |    0 |     1
 2 |  17 | 2                                                                      |    0 |     1
 2 | 100 | 2                                                                      |    0 |     1

 m |   p | 0.908234 / 0.293023323234                                              | sign | decpt
 0 |   0 | 30995280170060404                                                      |    0 |     1
 2 |  17 | 30995280170060404                                                      |    0 |     1
 2 | 100 | 3099528017006040414571543806232511997222900390625                      |    0 |     1
```