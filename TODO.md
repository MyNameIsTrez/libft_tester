# TO DO
* Replace all char [] with char *
* Add all headers to HEADERS in Makefile as compilation requirements

* Add parameter & return descriptions for the part 1 & extra ft functions.
* Make binary files get ignored by their gitignore rule by reset --HARDing them or smth.
* Fix all existing tests by making them all use my own asserts, instead of Criterion functions.
* Rename all functions so they use proper snake_case, like isspace -> is_space
* Change all `int i` indices to `size_t i`
* Add my "line" VS Code snippet slashes to every file.
* Replace every variable named "number" with "nbr", "string" with "str" (and more?)


# TO DO just before evalling
* Run norminette on all files.
* `norminette $(git ls-tree -r master --name-only)`
* `git ls-tree -r master --name-only`
* Clone this repository.


# TO DO after evalling
* Maybe change all *chr to chr[], cause it makes it clearer it's about a string.
* Use `git push -u github main` to have `git push` push to my private copy of this repo by default.
* Use `git push -v` to see what `git push` pushes to by default.
* Use an alias for "NULL if the allocation fails.", and substitute any variants with it.
* Write basic tests for every function.
* Remove any consts that aren't from vanilla libft.
* Simplify str_not_chr.
* ft_memcmp doesn't pass libftdestructor.
* Maybe rename lstnew to lst_new and such, although this'd also require modifying the testers in testers/.
