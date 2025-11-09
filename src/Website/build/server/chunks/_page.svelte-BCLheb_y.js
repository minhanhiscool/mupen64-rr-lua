import { e as escape_html } from './escaping-CqgfEcN3.js';

function html(value) {
  var html2 = String(value ?? "");
  var open = "<!---->";
  return open + html2 + "<!---->";
}
function _page($$renderer, $$props) {
  $$renderer.component(($$renderer2) => {
    let { data } = $$props;
    console.log(data.content);
    $$renderer2.push(`<main><section id="wiki" class="mx-auto max-w-6xl p-16 pb-16"><div class="mb-12 flex flex-row items-center justify-center gap-4 text-3xl font-bold"><hr class="w-15 border-2 border-dashed border-red-600"/> <p>${escape_html(data.title)}</p> <hr class="w-15 border-2 border-dashed border-red-600"/></div> <div class="mx-auto flex max-w-4xl flex-col items-start">${html(data.content)}</div></section></main>`);
  });
}

export { _page as default };
//# sourceMappingURL=_page.svelte-BCLheb_y.js.map
