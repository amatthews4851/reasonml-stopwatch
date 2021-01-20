# Reason Stopwatch

This is a Create-React-App adopted to become written in ReasonML. All the `.re` files are in the `reason` directory. Those are then compiled to the `lib`, where they are then finally `rsync`d to the src folder, where React picks them up.

## Scripts

**`yarn dev`**

This is going to be your go-to script for actually dev-ing in the project. Runs the CRA start script, the BuckleScript compiler, and the rsync script at the same time

**`yarn start`**

Just the standard CRA start script

**`yarn re:build`**

Runs the BuckleScript compiler

**`yarn re:watch`**

Runs the BuckleScript compiler on watch mode
