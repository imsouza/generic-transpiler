# Generic Transpiler

A generic transpiler to convert a generic syntax to C++

# Example
input file [/input] (.g)

```
va = 3;

for(i in range (10)) {
    pi = 3;
    for(i in range (10)) {
        if (i < 20) {
            pi = 0;
        } else {
            pi = 2;
        }
    }
}
```

output file [/output] (.cpp)
```
#include <iostream>
using namespace std;
 int main() {
    int va=3;
    for(int i = 0; i < 10; i++){
        int pi=3;
        for(int i = 0; i < 10; i++){
            if(i<20){
                int pi=0;
            }
            else{
                int pi=2;
            }
        }
    }

    return 0;
}
```

output xml tree [/tree]
```
<tree>
    <var>
        va=3;
    </var>
    <for>
        for
    </for>
    <range>
        int i = 0; i < 10; i++
    </range>
    <var>
        pi=3;
    </var>
    <for>
        for
    </for>
    <range>
    int i = 0; i < 10; i++
    </range>
    <if>
        if
    </if>
    <comp>
        i
    </comp>
    <else>
        else
    </else>
    <var>
        pi=2;
    </var>
</tree>

```

# Run

```make && make run```

# OS Support

Linux

# Authors

Mateus Almeida

Joilnen Leite

# License

This project is licensed under the [MIT](https://github.com/imsouza/generic-transpiler/blob/main/LICENSE) License.