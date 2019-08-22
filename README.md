# Magic static

https://en.cppreference.com/w/cpp/language/storage_duration#Static_local_variables

## Objective
Checking if other threads block when the static variable is in the middle of being instantiated.

## Result
Threads block until the instance of "Magic static" is created.
```
Signaling from main
Threadmain: myid:140095477892864 Received signal
Threadmain: myid:140095425443584 Received signal
Threadmain: myid:140095467403008 Received signal
Threadmain: myid:140095456913152 Received signal
Threadmain: myid:140095352014592 Received signal
Threadmain: myid:140095435933440 Received signal
Threadmain: myid:140095320545024 Received signal
Threadmain: myid:140095310055168 Received signal
Threadmain: myid:140095299565312 Received signal
Foo() in the context of threadid 140095477892864
Threadmain: myid:140095404463872 Received signal
Threadmain: myid:140095393974016 Received signal
Threadmain: myid:140095383484160 Received signal
Threadmain: myid:140095372994304 Received signal
Threadmain: myid:140095362504448 Received signal
Threadmain: myid:140095446423296 Received signal
Threadmain: myid:140095341524736 Received signal
Threadmain: myid:140095331034880 Received signal
Threadmain: myid:140095488382720 Received signal
Threadmain: myid:140095289075456 Received signal
Threadmain: myid:140095414953728 Received signal
Foo() in the context of threadid 140095477892864
Foo() in the context of threadid 140095477892864
Foo() in the context of threadid 140095477892864
Foo() in the context of threadid 140095477892864
Threadmain: myid:140095425443584 Foo.mId:140095477892864
Threadmain: myid:140095320545024 Foo.mId:140095477892864
Threadmain: myid:140095467403008 Foo.mId:140095477892864
Threadmain: myid:140095435933440 Foo.mId:140095477892864
Threadmain: myid:140095488382720 Foo.mId:140095477892864
Threadmain: myid:140095404463872 Foo.mId:140095477892864
Threadmain: myid:140095383484160 Foo.mId:140095477892864
Threadmain: myid:140095393974016 Foo.mId:140095477892864
Threadmain: myid:140095299565312 Foo.mId:140095477892864
Threadmain: myid:140095352014592 Foo.mId:140095477892864
Threadmain: myid:140095372994304 Foo.mId:140095477892864
Threadmain: myid:140095362504448 Foo.mId:140095477892864
Threadmain: myid:140095446423296 Foo.mId:140095477892864
Threadmain: myid:140095331034880 Foo.mId:140095477892864
Threadmain: myid:140095456913152 Foo.mId:140095477892864
Threadmain: myid:140095477892864 Foo.mId:140095477892864
Threadmain: myid:140095414953728 Foo.mId:140095477892864
Threadmain: myid:140095341524736 Foo.mId:140095477892864
Threadmain: myid:140095310055168 Foo.mId:140095477892864
Threadmain: myid:140095289075456 Foo.mId:140095477892864
```
