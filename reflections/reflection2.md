# Sprint reflection 2
## Philip Seger

  This sprint turned out a little differently than our team expected/hoped. While last sprint was a lot of implementation and forward momentum, this sprint felt much more stagnant and we were unable to make as much progress as we thought, for a couple of reasons. Chiefly, the team got hung up on a couple different issues; integration proved to be a little harder task than first thought, and starting our logic solver implementation in C (versus the C++ we had been writing for graphics) caused hiccups. Hieu and I worked on the C logic, and many of the structs/Cube API work we had previously done were inconvenient to port over to C (and we were not fully aware how even to do that). This meant that we spent a lot of time but did not make a lot of code. Thankfully, towards the end of the sprint, we got back to making progress and figured out how to start the logic solving and work on that thread. 
  Personally, I feel I have not had enough time to devote to this course, mainly in the sense that I want to not just complete assignments but to go beyond on each one and more fully understand how things are working under the hood. In a similar vein, it seems that the project has been of chief concern, however a lot of the individual learning comes from the reading. I do not know if I have been balancing the two halves poorly, but I want to try next sprint to spend more time on the book reading as well, to better fully grasp all the content we are going through.

# Exercises done in C for this sprint

## Head First C exercises:

[Exercise 1 (properly done now)](https://github.com/segerphilip/ExercisesInC/tree/master/exercises/ex01)
[Exercise 2 (properly done now)](https://github.com/segerphilip/ExercisesInC/tree/master/exercises/ex02)
[Exercise 2.5](https://github.com/segerphilip/ExercisesInC/tree/master/exercises/ex02.5)
[Exercise 3](https://github.com/segerphilip/ExercisesInC/tree/master/exercises/ex03)

## ThinkOS exercises:

[Chapter 3 (previously done)](https://github.com/segerphilip/ExercisesInC/blob/master/reading_questions/thinkos.md#chapter-3)
[Chapter 4 (previously done)](https://github.com/segerphilip/ExercisesInC/blob/master/reading_questions/thinkos.md#chapter-4)

# Exam question

**Q:** RAM and SSDs are pretty fast nowadays. However, fun little inconsistencies between the two can result in weird data. Let’s say you are developing a text editor, and you are adding the functionality to read files from the SSD, make changes, and save them back onto the SSD. You also want to make this as fast as possible. What are some considerations you must keep in mind?

**A:** A couple options: When reading a file, it is a slow process from SSD. Want to make sure it doesn’t block for significantly large files. Want to be able to save the file in a way that won’t cause problems if another change is made as it is being saved to SSD. Making the text editor snappy means leaving content in RAM, however if a crash happens you need to recover gracefully with minimal data loss. Saving constantly to SSD on any letter change causes a lot of R/W, which can decrease drive life.

