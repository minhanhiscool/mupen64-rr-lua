import matter from 'gray-matter';
import { Marked } from 'marked';
import * as fs from 'node:fs';
import * as path from 'node:path';
import { r as redirect, e as error } from './index-Djsj11qr.js';
import { d as doc_filesystem_to_friendly_name } from './DocNameConverter-CjZmka5j.js';
import { g as get_doc_paths } from './DocFetcher-DoAXUQfU.js';

const DOCS_DIR = "../../docs/win";
const load = async ({ params }) => {
  const doc_paths = await get_doc_paths();
  if (params.slug == "") {
    redirect(307, `/docs/win/${doc_paths[0]}`);
  }
  const file_path = path.join(DOCS_DIR, `${params.slug}.md`);
  if (!fs.existsSync(file_path)) {
    error(404, "Document not found");
  }
  const file = fs.readFileSync(file_path, "utf-8");
  const { content } = matter(file);
  const marked2 = new Marked({
    hooks: {
      postprocess(html2) {
        html2 = html2.replaceAll("<p", '<p class="y-2"');
        html2 = html2.replaceAll("<h1", '<h1 class="my-4 text-3xl font-bold"');
        html2 = html2.replaceAll("<h2", '<h2 class="my-3 text-2xl"');
        html2 = html2.replaceAll("<h3", '<h3 class="my-2 text-xl"');
        html2 = html2.replaceAll("<code", '<code class="font-mono dark:bg-surface-2 bg-surface-2-light px-1"');
        html2 = html2.replaceAll(
          "<table",
          '<table class="my-4 w-full  text-sm rounded-lg overflow-hidden"'
        );
        html2 = html2.replaceAll(
          "<th",
          '<th class="bg-surface-2-light dark:bg-surface-2 px-3 py-2 text-left font-semibold"'
        );
        html2 = html2.replaceAll(
          "<td",
          '<td class="px-3 py-2 border border-surface-3 dark:border-surface-1"'
        );
        html2 = html2.replaceAll(
          "<tr",
          '<tr class="odd:bg-surface-1-light dark:odd:bg-surface-3 even:bg-surface-2-light dark:even:bg-surface-2 transition-colors"'
        );
        return html2;
      }
    }
  });
  const html = await marked2.parse(content);
  console.log(html);
  return {
    content: html,
    title: doc_filesystem_to_friendly_name(params.slug)
  };
};

var _page_server_ts = /*#__PURE__*/Object.freeze({
  __proto__: null,
  load: load
});

const index = 4;
let component_cache;
const component = async () => component_cache ??= (await import('./_page.svelte-BCLheb_y.js')).default;
const server_id = "src/routes/docs/win/[...slug]/+page.server.ts";
const imports = ["_app/immutable/nodes/4.DDUY9hmG.js","_app/immutable/chunks/rNwPnN3C.js","_app/immutable/chunks/oSUuz_k1.js","_app/immutable/chunks/BYzeTzr1.js"];
const stylesheets = [];
const fonts = [];

export { component, fonts, imports, index, _page_server_ts as server, server_id, stylesheets };
//# sourceMappingURL=4-CO9Pn3o3.js.map
