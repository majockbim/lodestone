# preface
- lodestone _is not_ opensource
- this document is for maintaining project consistency

# code style

## classes
case: `PascalCase`

## functions
case: `sanke_case` (capitals are allowed)

## variables
case: `camelCase`

## constants
case: `UPPER_SNAKE_CASE`

# commit messages
format: `[type]: message`
if related to an issue or pr, append `(#x)`

## types
- `feat`: new feature
- `fix`: bug fix
- `refactor`: code change that isn't a fix or feature
- `perf`: performance improvement
- `test`: adding or updating tests
- `docs`: documentation only
- `chore`: build, config, tooling, or tiny changes

## examples
- `feat: add dipole superposition (#3)`
- `fix: clamp field magnitude at singularity`
- `refactor: extract solver into some class (#5)`
