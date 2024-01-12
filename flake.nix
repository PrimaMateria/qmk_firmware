{
  description = "Shell for compiling qmk";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };
  outputs = inputs@{ self, nixpkgs, utils, ... }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };
      in
      {
        devShell = pkgs.mkShell rec {
          name = "nix.shell.qmk.primamateria";
          packages = with pkgs; [
            qmk
            gnumake
            gcc
            gcc-arm-embedded
          ];

          shellHook = ''
            alias left="make CONVERT_TO=promicro_rp2040 ferris/sweep:primamateria:uf2-split-left"
            alias right="make CONVERT_TO=promicro_rp2040 ferris/sweep:primamateria:uf2-split-right"
            alias edit="nvim ./keyboards/ferris"

            echo "${name} started"
          '';
        };
      });
}
