import { e as escape_html } from './escaping-CqgfEcN3.js';
import { F as noop, E as writable } from './exports-BzHwARwz.js';
import { g as getContext } from './context-CXhJZien.js';

function create_updated_store() {
  const { set, subscribe } = writable(false);
  {
    return {
      subscribe,
      // eslint-disable-next-line @typescript-eslint/require-await
      check: async () => false
    };
  }
}
const is_legacy = noop.toString().includes("$$") || /function \w+\(\) \{\}/.test(noop.toString());
if (is_legacy) {
  ({
    url: new URL("https://example.com")
  });
}
const stores = {
  updated: /* @__PURE__ */ create_updated_store()
};
({
  check: stores.updated.check
});
function context() {
  return getContext("__request__");
}
const page$1 = {
  get error() {
    return context().page.error;
  }
};
const page = page$1;
function _error($$renderer, $$props) {
  $$renderer.component(($$renderer2) => {
    $$renderer2.push(`<main><section class="bg-hero p-16 shadow-md"><div class="mx-auto max-w-6xl"><div class="flex flex-col items-center justify-center gap-12 text-white"><p class="text-4xl">${escape_html(page.error?.message)}</p> <a class="link" href="https://mupen64.com">Back to the Homepage</a></div></div></section></main>`);
  });
}

export { _error as default };
//# sourceMappingURL=_error.svelte-D_9zyoRl.js.map
