# [James Grenning&#39;s Blog](https://blog.wingman-sw.com/)

- Blogging about Agile Development, especially embedded. Follow me on twitter: jwgrenning

[![James Grenning's Blog](https://blog.wingman-sw.com/wp-content/uploads/2014/12/cropped-Front-Row-Seats.jpg)](https://blog.wingman-sw.com/)

# TDD Guided by ZOMBIES

Have you had a hard time figuring out where to start with Test-Driven Development. What if ZOMBIES could help you build code that does exactly what you think it is supposed to do? What if ZOMBIES at the same time help you to build a test harness that can help you keep your code clean and behaving properly for a long and useful life? What if ZOMBIES could help!

![](https://blog.wingman-sw.com/files/img/zombies.jpg)

I’m not talking about those zombies! ZOMBIES is an acronym.

One of the seemingly odd things I saw back in 1999 when Kent Beck, Ron Jeffries and others demonstrated Test-Driven Development, was how they always started with the simplest cases, working their way deliberately to the more involved cases. For example, they’d first ask how would the object respond right after it is initialized? They would add one behavior at a time. Initially each behavior specified in a test scenario was an opportunity to try interface ideas. The early tests usually had hard-coded return results. The implementations were so simple ZOMBIES could do it.

People new to TDD often struggle with what test to write. It’s hard to know where to start or what test to write next. It’s hard to know when you are done, and it’s scary to think you will leave some incomplete code behind. Scary! How can ZOMBIES help with scary?!

I’ve come to rely on ZOMBIES to help explain how I figure out the next test, and what I am considering as I am writing the test. I find that ZOMBIES help me when I am stuck on a programming problem. ZOMBIES help find a logical next step. ZOMBIES help me keep on the firm footing of continually establishing cause and effect. ZOMBIES help me hone my procrastination skills, by suggesting what to do now and what to put off until later. Procrastination skills!? It is a skill to develop and master. Only use your procrastination skills for good.

Let me spell out ZOMBIES and explain the algorithm:

* **`Z`** – `Zero`
* **`O`** – `One`
* **`M`** – `Many (or More complex)`
* **`B`** – `Boundary Behaviors`
* **`I`** – `Interface definition`
* **`E`** – `Exercise Exceptional behavior`
* **`S`** – `Simple Scenarios, Simple Solutions`

When test-driving, guided by ZOMBIES, the first test **S**cenarios are for **S**imple post-conditions of a just created object. These are the **Z**ero cases. While defining the **Z**ero cases, take care to design the **I**nterface and capture the **B**oundary **B**ehaviors in your test **S**cenarios. Keep it **S**imple, both **S**olutions and **S**cenarios. You’ll find that hard. Once progress is made on the **Z**ero cases, move to the next special **B**oundary case, testing the **B**ehavior desired when transitioning from **Z**ero to **O**ne. To do so there are likely other **I**nterfaces to define and use in new test **S**cenarios. Once the **B**oundary **B**ehaviors between **Z**ero and **One** (and possibly back to **Z**ero from **O**ne) have been captured in tests, move on to start to generalize your design now dealing with **M**ore complex **S**cenarios and **M**any items being managed. Often there are new **B**oundary conditions to be concerned with. Finally review your work and make sure you consider and **E**xercise the **E**xceptional things that might happen.

> (I was hoping to work ‘P’ for procrastination into the acronym. ZOMBIE Apocalypse?)

ZOMBIES is not your usual sequential acronym. It is only partially sequential. It has two dimensions. One Axis is ZOM^[[ZOM]](https://blog.wingman-sw.com/tdd-guided-by-zombies#fn1)^ the orthogonal axis if BIE, with simple test scenarios (several reasons for the S) bringing them together.

Zombies are chaotic, though ZOMBIES are orderly and purposeful.

![](https://blog.wingman-sw.com/files/img/zombies-2D.png)

Initial test **S**cenarios follow the **ZOM** pattern from simple to complex, while the things we consider come from  **BIE** , all the time aiming for **S**implicity in test **S**cenarios and production code **S**olutions.

Are you ready for some code? Nothing like an example to understand ZOMBIES. The rest of the article explains ZOMBIES role in test-driving a simple C module that implements a `CircularBuffer` or First-In First-Out (FIFO) data structure. This `CircularBuffer` will hold a series of integers. We can `Put()` a new integer in and `Get()` the oldest out. If it `IsFull()` it will reject all new attempts to put. If it `IsEmpty()`, a get returns a default value that you can specify during `Create()`. There are quite a few usage scenarios that have to be tested, specially around the boundaries and exceptional things that can happen. Just to refresh your memory, here is a diagram to illustrate a `CircularBuffer` implementation.

![](https://blog.wingman-sw.com/files/img/CircularBuffer-1.png)

Before starting, make a list of **S**cenarios to test, in no particular order:

* Wrap around
* Overflow
* Underflow
* Empty
* Full
* Happy path – FIFO

I use this example in my TDD for Embedded C or C++ training courses. Engineers are drawn to the more challenging parts of the implementation, like wrap around, overflow and underflow. They were taught to go after the tough problems first. In TDD guided my ZOMBIES, start with the easy stuff and build a foundation of simple behaviors first, procrastinating skillfully. Then work out the more involved scenarios and behaviors one at a time.

For `CircularBuffer`, the zero scenario focuses on the test cases for the newly created container: it is empty; it is not full. Testing that the new `CircularBuffer` is empty and not full leads to defining interfaces for the production code. The test cases record critical boundary behaviors. Let’s see what these tests look like in [CppUTest](http://cpputest.org/), an open source test harness (designed for embedded C and C++ programmers in mind).

|

```
// CircularBufferTest.cpp
#include "CppUTest/TestHarness.h"
 
extern "C"
{
#include "CircularBuffer.h"
}
 
TEST_GROUP(CircularBuffer)
{
    CircularBuffer * buffer;
 
    void setup()
    {
        buffer = CircularBuffer_Create();
    }
 
    void teardown()
    {
        CircularBuffer_Destroy(buffer);
    }
};
 
TEST(CircularBuffer, can_be_created_and_destroyed)
{
}
 
TEST(CircularBuffer, is_empty_after_creation)
{
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
}
 
TEST(CircularBuffer, is_not_full_after_creation)
{
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
}
```

|  |
| - |

> NOTE: In all the examples, the tests are written one at a time, and the code to pass each test is written incrementally. I’m just showing them in batches. I’ll also take advantage of `calloc()`’s behavior of initializing allocated memory to zero. So while using `calloc()` I won’t explicitly initialize member variables to zero.

The thing that really bothers people new to TDD, is that to pass these tests, this is all the code that is needed:

|

```
// CircularBuffer.h
#ifndef CIRCULAR_BUFFER_INCLUDED
#define CIRCULAR_BUFFER_INCLUDED
 
#include <stdbool.h>
 
typedef struct CircularBufferStruct CircularBuffer;
 
CircularBuffer * CircularBuffer_Create(void);
void CircularBuffer_Destroy(CircularBuffer *);
bool CircularBuffer_IsEmpty(CircularBuffer *);
bool CircularBuffer_IsFull(CircularBuffer *);
 
#endif
```

|  |
| - |

|

```
// CircularBuffer.c
#include "CircularBuffer.h"
 
struct CircularBufferStruct
{
    int place_holder_delete_me_soon;
};
 
CircularBuffer * CircularBuffer_Create(void)
{
    CircularBuffer * self = (CircularBuffer *)calloc(1, sizeof(CircularBuffer));
    return self;
}
 
void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}
 
bool CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return true;
}
 
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return false;
}
```

|  |
| - |

With that code, there are often gasps and shaking heads from the people new to TDD. The fear of past programming mistakes shows on their faces. “You are not using or storing the Create parameters.”, “IsEmpty and IsFull are nowhere close to right” “What if you forget to come back and change those hard coded results!?”

With ZOMBIES helping, it may seem scary, but the next action is **S**imple, attack one of the hard coded return statements right now, and add the other to your test list if its not already there.

If you look at the effort to get the code and tests to this point, most the effort is spent to keep the compiler and linker happy. Due to the **S**imple **S**cenarios coming first, and the incomplete but **S**imple **S**olution that passes all the test, we can be confident that tests pass for the intended **B**ehavior and fail for unintended behavior.

If the next test `Put()` a value into the `CircularBuffer` it would not be empty. Hard coding `IsFull()` would not work for both **S**cenarios. So write this **B**oundary **B**ehavior test that defines the `Put()` **I**nterface that stores **O**ne item.

|

```
TEST(CircularBuffer, is_not_empty_after_put)
{
    CircularBuffer_Put(buffer, 42);
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
}
```

|  |
| - |

Expanding the **I**nterface further and defining another **B**oundary **B**ehavior **S**cenario, this tests transitions the `CircularBuffer` back to empty. Next make sure `Get()` returns what was `Put()` for this **O**ne item in the FIFO **B**oundary **B**ehavior.

|

```
TEST(CircularBuffer, is_empty_after_put_then_get)
{
    CircularBuffer_Put(buffer, 42);
    CircularBuffer_Get(buffer);
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
}
 
TEST(CircularBuffer, get_equals_put_for_one_item)
{
    CircularBuffer_Put(buffer, 42);
    LONGS_EQUAL(42, CircularBuffer_Get(buffer));
}
```

|  |
| - |

When we do the **S**implest thing that moves the code toward the solution we have in mind ^[[DTSTTCPW]](https://blog.wingman-sw.com/tdd-guided-by-zombies#fn2)^ , very little production code is needed to pass these tests. Whenever we can get by with an incomplete solution in the production code, it means one or more tests are needed to fully exercise the code.

|

```
bool CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return self->index == self->outdex;
}
 
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return false;
}
 
void CircularBuffer_Put(CircularBuffer * self, int value)
{
    self->index++;
}
 
int CircularBuffer_Get(CircularBuffer * self)
{
    self->outdex++;
    return 42;
}
```

|  |
| - |

More gasps and groans, as another hard coded value is introduced. The horror of not even saving the value that is `Put()`. It can be pretty scary to program with ZOMBIES, until you get to know them.

I’ve seen thousands of programmers solve this problem (in my training classes). Many cannot resist putting in an implementation for `IsFull()` right now. I’ve seen virtually no programmers get it right on the first try, especially if they use the `index` and `outdex` to implement `IsFull()`. To the TDD learner, it is scary to procrastinate, but you can always add anything you think you might forget to the test list. I think it is scarier to leave behind untested code for such an important case.

What have we accomplished so far with help from ZOMBIES? To the novice, “you are testing nothing!”. Sure enough, but I think I’ve accomplished a several important things:

* The interface is nearly complete and we can see where it is going. If it was inconvenient to use, we’d know already!
* The the code is proving to be testable.
* A lot of complier syntax has been tamed for our needs.
* Several important boundary conditions have been captured in tests we are confident in.
* I can devote less of my brain to those boundary cases as I define the rest of the behaviors for the `CircularBuffer`. The tests will tell me if my code stops following the behaviors defined in the test scenarios.
* We have explored a specific mechanism that the `CircularBuffer` can use to report that it is empty or not empty. Saving the value has nothing to do with determining `IsEmpty()`.

Now that the **Z**ero/**O**ne **B**oundary **B**ehavior **S**cenarios have been cataloged and the **I**nterface has evolved, let’s finally make this a FIFO as we define the first scenario for **M**any contained items.

|

```
TEST(CircularBuffer, put_get_is_fifo)
{
    CircularBuffer_Put(buffer, 41);
    CircularBuffer_Put(buffer, 42);
    CircularBuffer_Put(buffer, 43);
    LONGS_EQUAL(41, CircularBuffer_Get(buffer));
    LONGS_EQUAL(42, CircularBuffer_Get(buffer));
    LONGS_EQUAL(43, CircularBuffer_Get(buffer));
}
```

|  |
| - |

There are a couple things to consider at this step. How should we dynamically size the array to hold the values? We could do two allocations or one. If we are using the heap, we better make sure we put the allocated memory back when the `CircularBuffer` is destroyed. Then we also have to save and retrieve the value in a First-In First-Out manner.

Keeping it **S**imple, let’s make those changes one at a time. First FIFO, then dynamic allocation. For now, we can hard code the size of the `values` array. It will be a little easier to keep to code working with a singe change. Repeat after me: It’s easier to keep code working than to fix it after you break it.

|

```
#include "CircularBuffer.h"
 
struct CircularBufferStruct
{
    int index;
    int outdex;
    int values[10];
};
 
CircularBuffer * CircularBuffer_Create(void)
{
    CircularBuffer * self = (CircularBuffer *)calloc(1, sizeof(CircularBuffer));
    return self;
}
 
//snip
 
bool CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return self->index == self->outdex;
}
 
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return false;
}
 
void CircularBuffer_Put(CircularBuffer * self, int value)
{
    self->values[self->index] = value;
    self->index++
}
 
int CircularBuffer_Get(CircularBuffer * self)
{
    int value = self->values[self->outdex];
    self->outdex++;
    return value;
}
```

|  |
| - |

I’d like to add **B**oundary tests for `IsFull()`, but up to this point there is no notion of capacity. So let’s introduce capacity to the tests and code. It will be handy for callers to access the `CircularBuffer`’s capacity. Also we’ll have to add a `capacity` parameter to `Create()` function. These tests drive the initial **I**terface, and the adding of `capacity` to `Create()`.

|

```
TEST(CircularBuffer, report_capacity)
{
    LONGS_EQUAL(CAPACITY, CircularBuffer_Capacity(buffer));
}
 
TEST(CircularBuffer, capacity_is_adjustable)
{
    CircularBuffer * buffer = CircularBuffer_Create(CAPACITY+2);
    LONGS_EQUAL(CAPACITY+2, CircularBuffer_Capacity(buffer));
    CircularBuffer_Destroy(buffer);
}
```

|  |
| - |

The `capacity_is_adjustable` test established cause and effect of tying `Create()` to `Capacity()`.

Here’s the implementation of `Capacity()` and the associated changes. We did not actually use the `capacity` yet.

|

```
//snip
 
typedef struct CircularBufferStruct
{
    int index;
    int outdex;
    int capacity;
    int values[10];
} CircularBuffer;
 
CircularBuffer * CircularBuffer_Create(int capacity)
{
    CircularBuffer * self = calloc(1, sizeof(CircularBuffer));
    self->capacity = capacity;
    return self;
}
 
//snip
 
unsigned int CircularBuffer_Capacity(CircularBuffer * self)
{
    return self->capacity;
}
```

|  |
| - |

Now the code is ready to add dynamic allocation. Given that: 1) we already have a fixed size array working 2) capacity has been introduced. There is not a really good way for the test to force the array allocation with `malloc()` or `calloc()`, so we treat it as a refactoring, changing the structure without changing the external behavior.

|

```
#include "CircularBuffer.h"
 
struct CircularBufferStruct
{
    int index;
    int outdex;
    int capacity;
    int values[];
};
 
CircularBuffer * CircularBuffer_Create(int capacity)
{
    int size = sizeof(CircularBuffer) + capacity * sizeof(int);
    CircularBuffer * self = (CircularBuffer *)malloc(size);
    self->capacity = capacity;
    self->index = 0;
    self->outdex = 0;
    return self;
}
 
void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}
```

|  |
| - |

This step usually does not go too smoothly for people in my training. There are a lot of details to get right. I chose the single allocation implementation, where `int values[]` has to be last member of the `struct`, the `malloc()` size must take into account the size of the `struct`, and the space needed for `capacity` number if `int`s, not to mention that we can’t allow a memory leak. Thankfully, CppUTest has leak detection. You can see that changing from `calloc()` to `malloc()` has to be accompanied with explicit member variable initializations.

With capacity and dynamic sizing complete it is finally possible to completely fill the buffer.

|

```
static void fillItUp(CircularBuffer * buffer)
{
    for (int i = 0; i < CircularBuffer_Capacity(buffer); i++)
        CircularBuffer_Put(buffer, i);
}
 
TEST(CircularBuffer, fill_to_capacity)
{
    fillItUp(buffer);
    CHECK_TRUE(CircularBuffer_IsFull(buffer));
}
```

|  |
| - |

`fillItUp()` is a helper function. It started life as an in-line `for` loop in the test case, primitively filling the buffer. I generally don’t like loops in unit tests. I’d rather read a test top to bottom as a scenario specification. Extracting `fillItUp()` from the test cleans up the test; `fillItUp()` could be handy for other tests too.

Here is a wrong `IsFull()` that works as long as we have not yet wrapped.

|

```
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return self->index == self->capacity;
}
```

|  |
| - |

This implementation passes the test, but we know it won’t survive wrapping. This simple and wrong implementation makes me think of another **B**oundary **Behavior** that should be tested. Like we did with `IsEmpty()` let’s transition away from being full.

|

```
TEST(CircularBuffer, is_not_full_after_get_from_full_buffer)
{
    fillItUp(CircularBuffer_Capacity(buffer));
    CircularBuffer_Get(buffer);
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
}
```

|  |
| - |

Here is another wrong implementation, but this will all change with wrapping so we take the passing **B**oundary test as a progress.

|

```
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return (self->index - self->outdex) == self->capacity;
}
```

|  |
| - |

Now finally, we get to one of the final **B**oundary cases. The **S**enario that many engineers think of first: wrapping!

|

```
TEST(CircularBuffer, force_a_buffer_wraparound)
{
    CircularBuffer * buffer = CircularBuffer_Create(2);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Get(buffer);
    CircularBuffer_Put(buffer, 3);
    LONGS_EQUAL(2, CircularBuffer_Get(buffer));
    LONGS_EQUAL(3, CircularBuffer_Get(buffer));
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}
```

|  |
| - |

CppUTest reports after writing this test that memory was corrupted. Because wrapping is not yet implemented, the `int` after the end of the allocated memory was overwritten. CppUTest overrides memory allocation and adds a guard value at the end of the allocated memory. If the guard is changed, CppUTest lets you know.

The existing tests help keep the code working during this change. It is a small change to `Put()` and `Get()`.

|

```
void CircularBuffer_Put(CircularBuffer * self, int value)
{
    self->values[self->index] = value;
    self->index++;
    if (self->index == self->capacity)
        self->index = 0;
}
 
int CircularBuffer_Get(CircularBuffer * self)
{
    int value = self->values[self->outdex];
    self->outdex++;
    if (self->outdex == self->capacity)
        self->outdex = 0;
    return value;
}
```

|  |
| - |

That implementation broke `IsFull()` **B**oundary **B**ehavior just as suspected.

```
compiling CircularBuffer.c
Building archive lib/libCircularBuffer.a
r - objs/CircularBuffer.o
Linking CircularBuffer_tests
Running CircularBuffer_tests
..
CircularBufferTest.cpp:95: error: Failure in TEST(CircularBuffer, fill_to_capacity)
    CHECK_TRUE(CircularBuffer_IsFull(buffer)) failed

..........
Errors (1 failures, 12 tests, 12 ran, 15 checks, 0 ignored, 0 filtered out, 2 ms)
```

That failure may have been surprising. It’s time to look at the sketch of a wrapped full buffer, and what it means to our current implementation.

![](https://blog.wingman-sw.com/files/img/CircularBuffer-2.png)

After wrapping `self->index` and `self->outdex` are the same! Full and empty can’t be the same! That’s not logical.

During my training exercise, many programmers get stuc here trying to get `IsFull()` working using only `self->index`, `self->outdex` and `self->capacity`. I usually suggest they look for a **S**imple **S**olution that will work.

In training, I’ll sometimes provide this nudge: “How many items are in an empty buffer?”. “How many are in a full buffer?”

A simple counter will do. (there are other solutions)

Here is the code just after introducing `self->count` for `IsEmpty()` and `IsFull()`. I also extracted the duplcate wrapping logic out of `Put()` and `Get()`. Notice I also extracted duplicate code into `nextIndex()`, a local helper function.

|

```
#include "CircularBuffer.h"
 
struct CircularBufferStruct
{
    int index;
    int outdex;
    int capacity;
    int count;
    int values[];
};
 
CircularBuffer * CircularBuffer_Create(int capacity)
{
    int size = sizeof(CircularBuffer) + capacity * sizeof(int);
    CircularBuffer * self = (CircularBuffer *)malloc(size);
    self->capacity = capacity;
    self->index = 0;
    self->outdex = 0;
    self->count = 0;
    return self;
}
 
void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}
 
bool CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return self->count == 0;
}
 
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return self->count == self->capacity;
}
 
static unsigned int nextIndex(CircularBuffer * self, unsigned int dex)
{
    dex++;
    if (dex >= self->capacity)
        dex = 0;
    return dex;
}
 
void CircularBuffer_Put(CircularBuffer * self, int value)
{
    self->count++;
    self->values[self->index] = value;
    self->index = nextIndex(self, self->index);
}
 
int CircularBuffer_Get(CircularBuffer * self)
{
    int value;
    self->count--;
    value = self->values[self->outdex];
    self->outdex = nextIndex(self, self->outdex);
 
    return value;
}
int CircularBuffer_Capacity(CircularBuffer * self)
{
    return self->capacity;
}
```

|  |
| - |

Just to be sure, lets add a test to make sure `IsFull()` works after wrapping. I don’t expect a problem.

|

```
TEST(CircularBuffer, full_after_wrapping)
{
    CircularBuffer * buffer = CircularBuffer_Create(2);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Get(buffer);
    CircularBuffer_Put(buffer, 3);
    CHECK_TRUE(CircularBuffer_IsFull(buffer));
    CircularBuffer_Destroy(buffer);
}
```

|  |
| - |

Expectation met!

Are we done? No! What about he **E** in ZOMBIES! Now that we have all the happy paths, what can go wrong, most engineers are quick to think of these abuse cases when we’re first composing a test list.

|

```
TEST(CircularBuffer, put_to_full_fails)
{
    CircularBuffer * buffer = CircularBuffer_Create(1);
    CHECK_TRUE(CircularBuffer_Put(buffer, 1));
    CHECK_FALSE(CircularBuffer_Put(buffer, 2));
    CircularBuffer_Destroy(buffer);
}
 
TEST(CircularBuffer, get_from_empty_returns_default_value)
{
    LONGS_EQUAL(DEFAULT_VALUE, CircularBuffer_Get(buffer));
}
```

|  |
| - |

Here are the completed `Put()`, `Get()` implementations.

|

```
struct CircularBufferStruct
{
    int index;
    int outdex;
    int capacity;
    int count;
    int defaultValue;
    int values[];
};
 
CircularBuffer * CircularBuffer_Create(int capacity, int defaultValue)
{
    int size = sizeof(CircularBuffer) + capacity * sizeof(int);
    CircularBuffer * self = (CircularBuffer *)malloc(size);
    self->capacity = capacity;
    self->index = 0;
    self->outdex = 0;
    self->count = 0;
    self->defaultValue = defaultValue;
    return self;
}
 
//snip
 
bool CircularBuffer_Put(CircularBuffer * self, int value)
{
    if (CircularBuffer_IsFull(self))
        return false;
 
    self->count++;
    self->values[self->index] = value;
    self->index = nextIndex(self, self->index);
    return true;
}
 
int CircularBuffer_Get(CircularBuffer * self)
{
    int value;
    if (CircularBuffer_IsEmpty(self))
        return self->defaultValue;
 
    self->count--;
    value = self->values[self->outdex];
    self->outdex = nextIndex(self, self->outdex);
 
    return value;
}
 
//snip
```

|  |
| - |

Hmmm, while we are exploring things that can go wrong, let make sure putting to full and getting from empty does not harm the buffer’s integrity. These are belt and suspender tests, I don’t really expect them to fail.

|

```
TEST(CircularBuffer, put_to_full_does_not_damage_contents)
{
    CircularBuffer * buffer = CircularBuffer_Create(1, DEFAULT_VALUE);
    CircularBuffer_Put(buffer, 1);
    CHECK_FALSE(CircularBuffer_Put(buffer, 2));
    LONGS_EQUAL(1, CircularBuffer_Get(buffer));
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}
 
 
TEST(CircularBuffer, get_from_empty_does_no_harm)
{
    CircularBuffer * buffer = CircularBuffer_Create(1, DEFAULT_VALUE);
    CircularBuffer_Get(buffer);
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
    CircularBuffer_Put(buffer, 1);
    CHECK_TRUE(CircularBuffer_IsFull(buffer));
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
    LONGS_EQUAL(1, CircularBuffer_Get(buffer));
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}
```

|  |
| - |

> Notice how this test is not as simple as the earlier tests. We try to make all the tests **S**imple, though some thwart that goal. This test could be split into several tests, but I don’t think in this case it helps much.

What else can go wrong! Are there other **E**ceptional or abusive scenarios. Could wrong parameters be passed to the `CircularBuffer` functions. A Quick review suggests tests may be warranted for these abuse **S**enarios:

* Create with a zero or negative length
* Passing in a NULL pointer where a buffer is expected
* Running out of heap

How to react to these is outside the scope of this article. You’d have to consider these for your application.

### The First Bug Fix!

Let’s toss a curve ball at the `CircularBuffer`. What if we discovered that this `CircularBuffer` had to be populated from an interrupt routine and read by an application task.

You may think nothing of it, but then again you might. Or will get some very mysterious behavior using the `CircularBuffer` in that concurrent environment. `Put()` and `Get()` have a shared variable (`self->count`)! There is a race condition! This code will eventually experience a catastrophic failure because `Put()` and `Get()` are not atomic operations. `self->count` will eventually be corrupted.

Doing some research we come across this [wikipedia article](https://en.wikipedia.org/wiki/Circular_buffer) on circular buffers. There is a solution that instead of shared counter, `Get()` is the only function to change `self->index` and `Put()` is the only function to chance `self->outdex`. The algorithm requires that there be an extra cell in `values[]`, while `Put()` will consider the buffer full when `self->index` gets within one cell of `self->outdex`.

This sounds like a significant change to the algorithm, but we have tests to notify us of any test scenarios that break during this **E**xceptional refactoring.

Here’s the production code after the refactoring:

|

```
//CircularBuffer.c
#include "CircularBuffer.h"
 
struct CircularBufferStruct
{
    int index;
    int outdex;
    int capacity;
    int defaultValue;
    int values[];
};
 
CircularBuffer * CircularBuffer_Create(int capacity, int defaultValue)
{
    int size = sizeof(CircularBuffer) + (capacity+1) * sizeof(int);
    CircularBuffer * self = (CircularBuffer *)malloc(size);
    self->capacity = capacity;
    self->index = 0;
    self->outdex = 0;
    self->defaultValue = defaultValue;
    return self;
}
 
void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}
 
bool CircularBuffer_IsEmpty(CircularBuffer * self)
{
    return self->index == self->outdex;
}
 
static unsigned int nextIndex(CircularBuffer * self, unsigned int dex)
{
    dex++;
    if (dex >= self->capacity+1)
        dex = 0;
    return dex;
}
 
bool CircularBuffer_IsFull(CircularBuffer * self)
{
    return nextIndex(self, self->index) == self->outdex;
}
 
bool CircularBuffer_Put(CircularBuffer * self, int value)
{
    if (CircularBuffer_IsFull(self))
        return false;
 
    self->values[self->index] = value;
    self->index = nextIndex(self, self->index);
    return true;
}
 
int CircularBuffer_Get(CircularBuffer * self)
{
    int value;
    if (CircularBuffer_IsEmpty(self))
        return self->defaultValue;
 
    value = self->values[self->outdex];
    self->outdex = nextIndex(self, self->outdex);
 
    return value;
}
 
int CircularBuffer_Capacity(CircularBuffer * self)
{
    return self->capacity;
}
```

|  |
| - |

Only four changes were needed:

* Add one to capacity in `Create()` and `nextIndex()`.
* Changes to `IsEmpty()` and `IsFull()`

That went really smoothly. Even though how we decided to implement some of the key decisions in `CircularBuffer`, in the end we could take them in stride. Early behaviors we easy to get right and keep right as the actual final solution took form.

### Final Thoughts

TDD guided by ZOMBIES helps me make progress in growing the behavior of code I am working on. It changed how I program long ago. Instead of writing out whole files and functions and then figuring out what is wrong, I define one behavior at a time and implement it as simply as possible, moving the code closer to the end goal as I envision it. Keeping the code working the whole time I am changing it. Hand in hand with that is refactoring when I see a way to make the code better. Again, keeping the code working because it is easier to keep a system working than to fix it after you break it.

Let me know if you would like to see the progression of the code. I could post that on another article or on github.

---

Footnotes

^[ZOM]^ When I wrote [Test-Driven Development for Embedded C](https://wingman-sw.com/tddec), I described a behavioral pattern of Test-Driven Developers that I called 0,1,N.. My friend [Tim Ottinger](http://agileotter.blogspot.com/) said, oh yeah, ZOM. There are only three numbers important in computing: Zero, One and Many. Zero and One are special cases. Many is the first generalization. ZOM has been helping me for years as I practiced and taught TDD. Thanks Tim! [[back]](https://blog.wingman-sw.com/tdd-guided-by-zombies#ZOM "Jump back to footnote 1 in the text.")

^[DTSTTCPW]^ Kent Beck showed this handy unpronounceable acronym to me back in 1999: DTSTTCPW. Spelling it out: Do The Simplest Thing That Could Possible Work. Thanks Kent! [[back]](https://blog.wingman-sw.com/tdd-guided-by-zombies#DTSTTCPW "Jump back to footnote 2 in the text.")

Zombies photo thanks to [Joel Friesen](http://flickr.com/photos/joelf/168770688/in/photostream/)
