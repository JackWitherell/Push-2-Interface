## Push 2 Interface
Experimental Interface for Ableton Push 2 (WIP)  
![push2](push2.png)  

# Inspiration
I originally wanted to make a program that could "run Doom" on the Ableton Push 2 but quickly found the programming aspect to be way over my head. While I was unexperienced at the time of writing this, I found the documentation for this hardware to be so good that I was able to get frames outputting on the device with only a little bit of fuss and knowledge about binary manipulation. I'd say that this is the single most ambitious programming project I've attempted to work on, and I'll finish it as I get more knowledge with C++

# Tricky Thickets and Sticky Wickets
Binary manipulation is very hard if you've never done it but with the right [StackOverflow Page](https://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit) and a whole lot of help from friends it gets much easier. The hardware doesn't read each pixel directly and in fact some bits need to first be flipped in a signal shaping pattern. Here's what the pattern looks like:

|HEX| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| - | - | - | - | - | - | - | - | - |
| FF| ■ | ■ | ■ | ■ | ■ | ■ | ■ | ■ |
| E7| ■ | ■ | ■ |   |   | ■ | ■ | ■ |
| F3| ■ | ■ | ■ | ■ |   |   | ■ | ■ |
| E7| ■ | ■ | ■ |   |   | ■ | ■ | ■ |

When run through this pattern for each 32 bit chunk in several 2M bulk transfers, color data will appear correctly. This was as simple as XORing the value of each pixel with 0xFFE7F3E7.

That's about as far I got. During this time I was also working on collecting printscr data from the OS but this process varies on each OS and I didn't want to bust open the documentation on RECTs in windows yet.
