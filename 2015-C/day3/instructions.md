# Day 3: Perfectly Spherical Houses in a Vacuum
## Part 1:
Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and
then an elf at the North Pole calls him via radio and tells him where to move
next. Moves are always exactly one house to the north (^), south (v), east (>),
or west (<). After each move, he delivers another present to the house at his
new location.

However, the elf back at the north pole has had a little too much eggnog, and
so his directions are a little off, and Santa ends up visiting some houses more
than once. HOW MANY HOUSES RECEIVE AT LEAST ONE PRESENT?

### For example:

- '>' delivers presents to 2 houses: one at the starting location, and one to
the east.
- '^>v<' delivers presents to 4 houses in a square, including twice to the
house at his starting/ending location.
- '^v^v^v^v^v' delivers a bunch of presents to some very lucky children at only
2 houses.

### Initial Thoughts:
We obviously want to use a graph. With a graph we can keep track of the visited
houses. We could also keep track of the number times a single node (house) was
visited, which may be involved in part 2 (but maybe not, either way it will be
good to approach the problem this way).

I don't know much about graphs tbh, and I've never truly coded one up. So I'm
going to go read CLRS for a bit then come back here to write some more thoughts
about an implementation that is suitable for this problem.

