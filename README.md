node-argon2
===========

## Development

### Dependencies

   - [node-gyp](https://github.com/nodejs/node-gyp) + its dependencies, and: `npm install -g node-gyp`

`cd` to directory you've cloned this repository, then run:

    node-gyp configure
    node-gyp build

Alternatively use CMake. First `npm install -g cmake-js` then:

    npm run-script build

Finally if you're using `n` to manage your Node, either:
  - symbolically link your header files to /usr/include, or
  - append `include_directories` [CMake] and `include_dirs` [gyp]
