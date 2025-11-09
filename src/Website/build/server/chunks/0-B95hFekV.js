import { g as get_doc_paths } from './DocFetcher-DoAXUQfU.js';
import 'node:fs';
import 'node:path';

const load = async () => {
  return {
    files: await get_doc_paths()
  };
};

var _layout_server_ts = /*#__PURE__*/Object.freeze({
  __proto__: null,
  load: load
});

const index = 0;
let component_cache;
const component = async () => component_cache ??= (await import('./_layout.svelte-Vror8jT4.js')).default;
const server_id = "src/routes/+layout.server.ts";
const imports = ["_app/immutable/nodes/0.D79XK_SF.js","_app/immutable/chunks/rNwPnN3C.js","_app/immutable/chunks/oSUuz_k1.js","_app/immutable/chunks/BYzeTzr1.js","_app/immutable/chunks/CyoFaybP.js","_app/immutable/chunks/ByzFFa6p.js","_app/immutable/chunks/CKneV1q7.js","_app/immutable/chunks/DTmis0lN.js","_app/immutable/chunks/Cm9kOdrZ.js","_app/immutable/chunks/D1joVCFQ.js"];
const stylesheets = ["_app/immutable/assets/0.oG-pWVi0.css"];
const fonts = [];

export { component, fonts, imports, index, _layout_server_ts as server, server_id, stylesheets };
//# sourceMappingURL=0-B95hFekV.js.map
