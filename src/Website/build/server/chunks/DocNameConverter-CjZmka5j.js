function doc_filesystem_to_friendly_name(name) {
  name = name.substring(3);
  name = name.split("-").join(" ");
  name = name.charAt(0).toUpperCase() + name.slice(1);
  return name;
}

export { doc_filesystem_to_friendly_name as d };
//# sourceMappingURL=DocNameConverter-CjZmka5j.js.map
