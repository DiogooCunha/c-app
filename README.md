# c-app 

## Documentation

* The documentation must be in the *.h file and follow this structure:

```c
/**
 * @brief Example of a function doc
 *
 * @param x First number to add
 * @param y Second number to add
 * @return Sum of the two parameters
 */
 int sum(int x, int y);
```

| Tag | Purpose |
|-----|---------|
| `@param` | Describe a parameter |
| `@return` | Describe return value |
| `@brief` | One-line summary |
| `@note` | Important note |
| `@warning` | Warn about gotchas |
| `@see` | Cross-reference |
| `@example` | Usage example |