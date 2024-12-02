(lang dune 3.12)

(using melange 0.1)

(source
 (github rikimasan/reason-expo))

(license MIT)

(maintainers "Kian Masri")

(authors "Kian Masri")

(homepage https://github.com/rikimasan/reason-expo)

(bug_reports https://github.com/rikimasan/reason-expo/issues)

(name reason-expo)

(package
 (name reason-expo)
 (synopsis "ReasonML Bindings for Expo")
 (description "ReasonML Bindings for Expo")
 (depends
  dot-merlin-reader
  (melange
   (and
    (>= 3.0.0)
    (< 5.0.0)))
  (ocaml
   (>= 5.1.0))
  (reason
   (>= 3.10.0))
  (ocaml-lsp-server :with-dev-setup)
  (ocamlformat :with-dev-setup)
  (ocaml-base-compiler :with-dev-setup)
  reason-react
  reason-react-native
  (opam-check-npm-deps :with-dev-setup)))

(generate_opam_files)
