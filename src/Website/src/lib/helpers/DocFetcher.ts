import { error } from '@sveltejs/kit';
import * as fs from 'node:fs';
import * as path from 'node:path';


function get_files_in_folder(folder_path: string) {
    try {
        const entries = fs.readdirSync(folder_path, { withFileTypes: true });
        const files = [];

        for (const entry of entries) {
            const full_path = path.join(folder_path, entry.name);
            if (entry.isFile()) {
                files.push(full_path);
            }
        }

        return files;
    } catch (error) {
        console.error('Error reading folder:', error);
        return [];
    }
}

function find_dir_upwards(target_dir_name: string, start_dir = ".") {
    let current_dir = path.resolve(start_dir);

    while (true) {
        const targetPath = path.join(current_dir, target_dir_name);

        if (fs.existsSync(targetPath) && fs.statSync(targetPath).isDirectory()) {
            return targetPath;
        }

        const parent_dir = path.dirname(current_dir);
        if (parent_dir === current_dir) {
            return null;
        }

        current_dir = parent_dir;
    }
}

export async function get_doc_paths() {
    try {
        const up_dir = find_dir_upwards('Website');
        if (!up_dir) {
            error(500, `Website directory not found`);
        }

        const docs_dir = path.join(up_dir, "../../docs/win");

        const files = get_files_in_folder(docs_dir);

        return files.map(file_path => path.parse(file_path).name);
    } catch (err) {
        error(500, err.message);
    }
}
