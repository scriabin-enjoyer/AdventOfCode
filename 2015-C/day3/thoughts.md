# Initial Thoughts:
We obviously want to use a graph. With a graph we can keep track of the visited
houses. We could also keep track of the number times a single node (house) was
visited, which may be involved in part 2 (but maybe not, either way it will be
good to approach the problem this way).

I don't know much about graphs tbh, and I've never truly coded one up. So I'm
going to go read CLRS for a bit then come back here to write some more thoughts
about an implementation that is suitable for this problem.

...

I am back having read a little bit about graphs now. I am still mulling over an
implementation. These are approaches I am currently considering: either
precalculate the worst case (actually it would be exact) size of the input or
suppose that the size of the input is arbitrary. The latter case feels more
"grown-up" in the sense that IRL you might not be able to find out the size of
a dataset before you process it. On the other hand, we can pre-allocate memory
for our entire graph.

...

After reading CLRS for a little bit (and also looking at an implementation of a
graph), I have formulated the general structure of the main driver code:

```c
int pos[2] <- { 0 };    // [x, y]
char move;
add_node pos;

while (move <- read_ch(input.txt) is not EOF) {
    // x +/- 1 or y +/- 1
    update_pos pos, move ;
    // store into adj_list; adj_matrix seems unnecessary currently
    add_node pos; 
}

return node_count()
```
Thus we only need to implement the following for the actual graph:
```c
void add_node(int[2]);
int node_count(Graph);
```
As for the implementation of the actual graph, I will need to learn how to use
structs, typedef, and most likely malloc/calloc. I think it will be possible to
avoid using any dynamic memory allocation, but only if I precalculate the input
size, in which case we can do everything statically.

Another thought: G is sparse if |E| << |V|^2 ("much less than"). Note |V|^2 is
that maximum size of an undirected graph with a mesh topology:
    If we have N nodes, and each node has an edge to every other node
    (including itself) then the number of edges |E| = |V|^2.
If our input is effectively random, then, intuitively, |E| << |V|^2 hence the
adjacency list representation is appropriate.
