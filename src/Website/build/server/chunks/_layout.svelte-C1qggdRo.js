function _layout($$renderer, $$props) {
  let { children } = $$props;
  children?.($$renderer);
  $$renderer.push(`<!----> <p class="mx-auto max-w-6xl text-center pb-16">⚠️ This wiki provides information about Mupen64 1.3.0-7. <br/> It may be updated before new versions are released.</p>`);
}

export { _layout as default };
//# sourceMappingURL=_layout.svelte-C1qggdRo.js.map
